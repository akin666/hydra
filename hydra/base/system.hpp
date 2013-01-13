/*
 * hydraengine.hpp
 *
 *  Created on: 11.1.2013
 *      Author: akin
 */

#ifndef HYDRASYSTEM_HPP_
#define HYDRASYSTEM_HPP_

#include <logic/logicscheduler.hpp>
#include <render/renderscheduler.hpp>

#ifndef HYDRA_CONFIG
# define HYDRA_CONFIG "config.json"
#endif

class System
{
private:
	render::Scheduler rscheduler;
	logic::Scheduler lscheduler;
public:
	System();
	~System();

	template <class GameLogicSystem>
	void createThread()
	{
		logic::ThreadPtr ptr( new GameLogicSystem );

		// add the thread to scheduler
		lscheduler.queue( ptr );
	}

	void uninitialize();

	bool initialize( String8 path = HYDRA_CONFIG );

	int run();
	bool shouldExit();
	bool shouldRestart();
};

#endif // HYDRASYSTEM_HPP_
