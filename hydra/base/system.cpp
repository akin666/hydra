/*
 * system.cpp
 *
 *  Created on: 12.1.2013
 *      Author: akin
 */

#include "system.hpp"
#include <singleton>

#include <log>
#include <graphics/graphicssystem.hpp>
#include <audio/audiosystem.hpp>
#include <network/networksystem.hpp>
#include <tpool/threadpool.hpp>

#include <json>

System::System()
: lscheduler( rscheduler )
{
}

System::~System()
{
	uninitialize();
}

void System::uninitialize()
{
	resetSingleton<network::System>();
	resetSingleton<audio::System>();
	resetSingleton<graphics::System>();
	resetSingleton<tpool::ThreadPool>();
	resetSingleton<Log>();
}

bool System::initialize( String8 path )
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
	LOG->message("Build micro version: %s %i", __DATE__ , __TIME__ );

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
	// TODO!, read threadCount from config.
	unsigned int threadCount = 0;
	unsigned int queryCount = tpool::ThreadPool::getHardwareThreadCount();
	if( threadCount < 1 || threadCount > 4*queryCount )
	{
		threadCount = queryCount;
	}
	if( !threadpool->initialize( threadCount ) )
	{
		LOG->error("%s:%i failed to initialize threadpool (c:%i)!" , __FILE__ , __LINE__ , threadCount );
		return false;
	}
	setSingleton<tpool::ThreadPool>( threadpool );

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

int System::run()
{
	// blocking, should start several threads to do their bidding
	lscheduler.start();

	// blocking, should block, until no more stuff to render and the lscheduler also has informed that all is done.
	rscheduler.start();

	return 0;
}

bool System::shouldExit()
{
	return false;
}

bool System::shouldRestart()
{
	return false;
}
