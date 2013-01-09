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
: renderScheduler( nullptr )
, scheduler( nullptr )
{
}

Thread::~Thread()
{
}

render::Scheduler *Thread::getRenderScheduler()
{
	return renderScheduler;
}

Scheduler *Thread::getScheduler()
{
	return scheduler;
}

entity::Context *Thread::getEntityContext()
{
	return &context;
}

void Thread::set( render::Scheduler& target )
{
	renderScheduler = &target;
}

void Thread::set( Scheduler& scheduler )
{
	this->scheduler = &scheduler;
}

} // namespace logic
