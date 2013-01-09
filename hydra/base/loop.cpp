/*
 * loop.cpp
 *
 *  Created on: 10.1.2013
 *      Author: akin
 */

#include "loop.hpp"

Loop::Loop()
: lsceduler( rscheduler )
{
}

Loop::~Loop()
{
}

logic::Scheduler& Loop::getScheduler()
{
	return lsceduler;
}

void Loop::run()
{
	// blocking, should start several threads to do their bidding
	lsceduler.start();

	// blocking, should block, until no more stuff to render and the lscheduler also has informed that all is done.
	rscheduler.start();
}
