/*
 * hydraengine.hpp
 *
 *  Created on: 11.1.2013
 *      Author: akin
 */

#ifndef HYDRASYSTEM_HPP_
#define HYDRASYSTEM_HPP_

#include <log>
#include <singleton>
#include <config/config.hpp>

#include <graphics/graphicssystem.hpp>
#include <audio/audiosystem.hpp>
#include <network/networksystem.hpp>

#include <logic/logicscheduler.hpp>
#include <render/renderscheduler.hpp>

#ifndef HYDRA_CONFIG
# define HYDRA_CONFIG "config.json"
#endif

template <class GameLogicSystem>
class System
{
private:
	graphics::System graphics;
	audio::System audio;
	cfg::Config config;
	Log log;
	network::System net;

	render::Scheduler rscheduler;
	logic::Scheduler lscheduler;

	GameLogicSystem *gls;
public:
	System()
	: lscheduler( rscheduler )
	, gls( nullptr )
	{
	}

	~System()
	{
		uninitialize();
	}

	void uninitialize()
	{
		net.uninitialize();
		audio.uninitialize();
		graphics.uninitialize();
		log.uninitialize();
	}

	bool initialize( string8 path = HYDRA_CONFIG )
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

		// Create the game thread
		gls = new GameLogicSystem;

		// add the thread to scheduler
		lscheduler.queue( *gls );

		return true;
	}

	int run()
	{
		{
			// blocking, should start several threads to do their bidding
			lscheduler.start();

			// blocking, should block, until no more stuff to render and the lscheduler also has informed that all is done.
			rscheduler.start();
		}

		return 0;
	}

	bool shouldExit()
	{
		return false;
	}

	bool shouldRestart()
	{
		return false;
	}
};

#endif // HYDRASYSTEM_HPP_
