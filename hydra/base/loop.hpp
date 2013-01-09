/*
 * loop.hpp
 *
 *  Created on: 10.1.2013
 *      Author: akin
 */

#ifndef LOOP_HPP_
#define LOOP_HPP_

#include <logic/logicscheduler.hpp>
#include <render/renderscheduler.hpp>

class Loop
{
private:
	render::Scheduler rscheduler;
	logic::Scheduler lsceduler;
public:
	Loop();
	~Loop();

	logic::Scheduler& getScheduler();

	// blocks, until all things have been run. logic & render.
	// premise is that, run is called from render thread!
	void run();
};

#endif // LOOP_HPP_
