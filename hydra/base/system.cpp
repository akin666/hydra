/*
 * system.cpp
 *
 *  Created on: 12.1.2013
 *      Author: akin
 */

#include "system.hpp"
#include <singleton>

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
	net.uninitialize();
	audio.uninitialize();
	graphics.uninitialize();
	log.uninitialize();
}

bool System::initialize( string8 path )
{
	if( !log.initialize( ) )
	{
		return false;
	}
	setSingleton<Log>( &log );

	// Hello log:
	LOG->message("Build micro version: %s %i", __DATE__ , __TIME__ );

	// Configuration
	if( !config.loadFromPath( path ) )
	{
		LOG->error("%s:%i failed to load primary configuration (%s)!" , __FILE__ , __LINE__ , path.c_str() );
		if( path == HYDRA_CONFIG || !config.loadFromPath( HYDRA_CONFIG ) )
		{
			if( path != HYDRA_CONFIG )
			{
				LOG->error("%s:%i failed to load secondary configuration (%s)!" , __FILE__ , __LINE__ , HYDRA_CONFIG );
			}
			return false;
		}
	}

	// Graphics
	if( !graphics.initialize( config ) )
	{
		return false;
	}

	// Audio
	if( !audio.initialize( config ) )
	{
		return false;
	}

	// Networking
	if( !net.initialize( config ) )
	{
		return false;
	}

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
