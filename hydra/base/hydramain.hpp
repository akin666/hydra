/*
 * hydraengine.hpp
 *
 *  Created on: 11.1.2013
 *      Author: akin
 */

#ifndef HYDRAMAIN_HPP_
#define HYDRAMAIN_HPP_

#include <logic/logicscheduler.hpp>
#include <render/renderscheduler.hpp>

#ifndef HYDRA_CONFIG
# define HYDRA_CONFIG "config.json"
#endif

namespace hydra {

class Main
{
private:
	render::Scheduler rscheduler;
	logic::Scheduler lscheduler;
public:
	Main();
	~Main();

	template <class GameLogicSystem>
	void createThread()
	{
		ProtothreadPtr ptr( new GameLogicSystem );

		// add the thread to scheduler
		lscheduler.queue( ptr );
	}

	void uninitialize();

	bool initialize( String8 path = HYDRA_CONFIG );

	int run();
	bool shouldExit();
	bool shouldRestart();
};

} // hydra

#endif // HYDRAMAIN_HPP_
