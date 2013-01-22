/*
 * system.cpp
 *
 *  Created on: 12.1.2013
 *      Author: akin
 */

#include "hydramain.hpp"
#include <singleton>

#include <log>
#include <graphics/graphicssystem.hpp>
#include <audio/audiosystem.hpp>
#include <network/networksystem.hpp>
#include <tpool/threadpool.hpp>

#include <json>

#ifndef CONFIG_SYSTEM_PATH
# define CONFIG_SYSTEM_PATH "system"
#endif

namespace hydra {

Main::Main()
: lscheduler( rscheduler )
{
}

Main::~Main()
{
	uninitialize();
}

void Main::uninitialize()
{
	resetSingleton<network::System>();
	resetSingleton<audio::System>();
	resetSingleton<graphics::System>();
	resetSingleton<tpool::ThreadPool>();
	resetSingleton<Log>();
}

bool Main::initialize( String8 path )
{
	Singleton<Log>::Ptr log( new Log );
	Singleton<graphics::System>::Ptr graphics( new graphics::System );
	Singleton<audio::System>::Ptr audio( new audio::System );
	Singleton<network::System>::Ptr	network( new network::System );
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

	// Graphics
	if( !graphics->initialize( config ) )
	{
		LOG->error("%s:%i failed to initialize graphics!" , __FILE__ , __LINE__ );
		return false;
	}
	setSingleton<graphics::System>( graphics );

	// Audio
	if( !audio->initialize( config ) )
	{
		LOG->error("%s:%i failed to initialize audio!" , __FILE__ , __LINE__ );
		return false;
	}
	setSingleton<audio::System>( audio );

	// Networking
	if( !network->initialize( config ) )
	{
		LOG->error("%s:%i failed to initialize networking!" , __FILE__ , __LINE__ );
		return false;
	}
	setSingleton<network::System>( network );

	return true;
}

int Main::run()
{
	// blocking, should start several threads to do their bidding
	lscheduler.start();

	// blocking, should block, until no more stuff to render and the lscheduler also has informed that all is done.
	rscheduler.start();

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

} // hydra
