/*
 * logicthread.cpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#include "logicthread.hpp"

namespace logic {

Thread::Thread()
: scheduler( nullptr )
{
	// create the entity context
	context = entity::Context::Ptr( new entity::Context );
}

Thread::~Thread()
{
}

Scheduler *Thread::getLogicScheduler()
{
	return scheduler;
}

entity::Context::Ptr Thread::getEntityContext()
{
	return context;
}

void Thread::set( Scheduler *scheduler )
{
	this->scheduler = scheduler;
}

} // namespace logic
