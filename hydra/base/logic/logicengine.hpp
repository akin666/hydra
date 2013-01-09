/*
 * engine.hpp
 *
 *  Created on: 10.1.2013
 *      Author: akin
 */

#ifndef LOGICENGINE_HPP_
#define LOGICENGINE_HPP_

#include <logic/logicscheduler.hpp>
#include <render/renderscheduler.hpp>

namespace logic {

class Engine
{
private:
	render::Scheduler rscheduler;
	logic::Scheduler lsceduler;
public:
	Engine();
	~Engine();

	logic::Scheduler& getScheduler();

	// blocks, until all things have been run. logic & render.
	// premise is that, run is called from render thread!
	void run();
};

} // logic

#endif // ENGINE_HPP_
