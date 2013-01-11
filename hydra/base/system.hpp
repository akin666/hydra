/*
 * hydraengine.hpp
 *
 *  Created on: 11.1.2013
 *      Author: akin
 */

#ifndef HYDRASYSTEM_HPP_
#define HYDRASYSTEM_HPP_

#include <log>
#include <config/config.hpp>

#include <graphics/graphicssystem.hpp>
#include <audio/audiosystem.hpp>
#include <network/networksystem.hpp>

#include <logic/logicscheduler.hpp>
#include <render/renderscheduler.hpp>

#ifndef HYDRA_CONFIG
# define HYDRA_CONFIG "config.json"
#endif

class System
{
private:
	graphics::System graphics;
	audio::System audio;
	network::System net;

	cfg::Config config;
	Log log;

	render::Scheduler rscheduler;
	logic::Scheduler lscheduler;
public:
	System();
	~System();

	template <class GameLogicSystem>
	GameLogicSystem *createThread()
	{
		GameLogicSystem *tmp = new GameLogicSystem;

		// add the thread to scheduler
		lscheduler.queue( *tmp );

		// once thread is finished, maybe logic scheduler should delete it.
		return tmp;
	}

	void uninitialize();

	bool initialize( string8 path = HYDRA_CONFIG );

	int run();
	bool shouldExit();
	bool shouldRestart();
};

#endif // HYDRASYSTEM_HPP_
