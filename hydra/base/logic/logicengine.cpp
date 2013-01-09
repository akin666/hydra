/*
 * logicengine.cpp
 *
 *  Created on: 10.1.2013
 *      Author: akin
 */

#include "logicengine.hpp"

namespace logic {

Engine::Engine()
: lsceduler( rscheduler )
{
}

Engine::~Engine()
{
}

logic::Scheduler& Engine::getScheduler()
{
	return lsceduler;
}

void Engine::run()
{
	// blocking, should start several threads to do their bidding
	lsceduler.start();

	// blocking, should block, until no more stuff to render and the lscheduler also has informed that all is done.
	rscheduler.start();
}

} // logic
