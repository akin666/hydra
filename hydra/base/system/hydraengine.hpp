/*
 * hydraengine.hpp
 *
 *  Created on: 11.1.2013
 *      Author: akin
 */

#ifndef HYDRAENGINE_HPP_
#define HYDRAENGINE_HPP_

#include <logic/logicengine.hpp>

namespace hydra {

template <
	class GameLogicSystem,
	class GraphicsSystem,
	class AudioSystem,
	class ConfigSystem,
	class LoggingSystem,
	class NetworkSystem
	>
class Engine
{
private:
	logic::Engine logicEngine;
	GameLogicSystem gls;
	GraphicsSystem graphics;
	AudioSystem audio;
	ConfigSystem config;
	LoggingSystem log;
	NetworkSystem net;
public:
	Engine()
	{
	}

	~Engine()
	{
		unInitialize();
	}

	void unInitialize()
	{
		net.unInitialize();
		audio.unInitialize();
		graphics.unInitialize();
		log.unInitialize();
		config.unInitialize();
	}

	bool initialize()
	{
		if( !config.initialize() )
		{
			return false;
		}

		// Log must register also to the global log thingy.
		if( !log.initialize( config ) )
		{
			return false;
		}

		if( !graphics.initialize( config ) )
		{
			return false;
		}

		if( !audio.initialize( config ) )
		{
			return false;
		}
		if( !net.initialize( config ) )
		{
			return false;
		}

		return true;
	}

	int run()
	{
		while( true )
		{
			logicEngine.run();
		}
		return 0;
	}
};

} // namespace hydra
#endif // HYDRAENGINE_HPP_
