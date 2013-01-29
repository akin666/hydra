/*
 * system.cpp
 *
 *  Created on: 12.1.2013
 *      Author: akin
 */

#include "hydramain.hpp"
#include <singleton>

#include <log>
#include <tpool/threadpool.hpp>

#include <json>

#include <glfw/glfwcontext.hpp>
#include <openal/openalcontext.hpp>

#ifndef CONFIG_SYSTEM_PATH
# define CONFIG_SYSTEM_PATH "system"
#endif

namespace hydra {

Main::Main()
{
}

Main::~Main()
{
	uninitialize();
}

void Main::uninitialize()
{
	resetSingleton<tpool::ThreadPool>();
	resetSingleton<Log>();
}

bool Main::initialize( String8 path )
{
	// Add render scheduler
	rscheduler = render::Scheduler::Ptr( new render::Scheduler );

	// Add logic scheduler
	lscheduler = logic::Scheduler::Ptr( new logic::Scheduler );

	Singleton<Log>::Ptr log( new Log );
	Singleton<tpool::ThreadPool>::Ptr threadpool( new tpool::ThreadPool );
	Singleton<Json::Value>::Ptr config( new Json::Value );

	if( !log->initialize( ) )
	{
		return false;
	}
	setSingleton<Log>( log );

	// Hello log:
	LOG->message("Build micro version: %i, %s" , __TIME__ , __DATE__ );

	// Configuration
	if( !Json::Helper::loadFromPath( config , path ) )
	{
		LOG->error("%s:%i failed to load primary configuration (%s)!" , __FILE__ , __LINE__ , path.c_str() );
		if( path == HYDRA_CONFIG || !Json::Helper::loadFromPath( config , HYDRA_CONFIG ) )
		{
			if( path != HYDRA_CONFIG )
			{
				LOG->error("%s:%i failed to load secondary configuration (%s)!" , __FILE__ , __LINE__ , HYDRA_CONFIG );
			}
			return false;
		}
	}
	setSingleton<Json::Value>( config );

	// Threading
	unsigned int queryCount = tpool::ThreadPool::getHardwareThreadCount();
	if( queryCount < 2 )
	{
		queryCount = 2;
	}
	unsigned int threadCount = Json::Helper::get( config , CONFIG_SYSTEM_PATH ".threadcount" , queryCount );
	if( threadCount < 1 || threadCount > 8*queryCount )
	{
		threadCount = queryCount;
	}
	if( !threadpool->initialize( threadCount ) )
	{
		LOG->error("%s:%i failed to initialize threadpool (c:%i)!" , __FILE__ , __LINE__ , threadCount );
		return false;
	}
	setSingleton<tpool::ThreadPool>( threadpool );
	LOG->message("Threads: %i + main.", threadCount );

	//////// Core
	{
		// TODO replace with factory? incase glfw is not the only one.
		glfw::Context *context = new glfw::Context();
		core = core::Context::Ptr( context );
	}
	if( !core->initialize( config ) )
	{
		LOG->error("%s:%i failed to initialize core!" , __FILE__ , __LINE__ );
		return false;
	}

	//////// Audio
	{
		// TODO replace with factory? incase openal is not the only one.
		openal::Context *context = new openal::Context();
		audio = audio::Context::Ptr( context );
	}
	if( !audio->initialize( config ) )
	{
		LOG->error("%s:%i failed to initialize audio!" , __FILE__ , __LINE__ );
		return false;
	}

/*	// Networking
	if( !network->initialize( config ) )
	{
		LOG->error("%s:%i failed to initialize networking!" , __FILE__ , __LINE__ );
		return false;
	}
	setSingleton<network::System>( network );
*/
	return true;
}

int Main::run()
{
	// blocking, should start several threads to do their bidding
	lscheduler->start();

	// blocking, should block, until no more stuff to render and the lscheduler also has informed that all is done.
	rscheduler->start();

	return 0;
}

bool Main::shouldExit()
{
	return false;
}

bool Main::shouldRestart()
{
	return false;
}

render::Scheduler::Ptr Main::getRenderer()
{
	return rscheduler;
}

logic::Scheduler::Ptr Main::getLogic()
{
	return lscheduler;
}

} // hydra
