/*
 * logicthread.cpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#include "logicthread.hpp"

namespace logic
{

Thread::Thread()
: renderqueue( nullptr )
, scheduler( nullptr )
{
}

Thread::~Thread()
{
}

render::Queue *Thread::getRenderQueue()
{
	return renderqueue;
}

Scheduler *Thread::getScheduler()
{
	return scheduler;
}

entity::Context *Thread::getEntityContext()
{
	return &context;
}

void Thread::setRenderQueue( render::Queue& rqueue )
{
	renderqueue = &rqueue;
}

void Thread::setScheduler( Scheduler& scheduler )
{
	this->scheduler = &scheduler;
}

} // namespace logic
