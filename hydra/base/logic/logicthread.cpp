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
{
}

Thread::~Thread()
{
}

render::Queue *Thread::getRenderQueue()
{
	return renderqueue;
}

void Thread::setRenderQueue( render::Queue& rqueue )
{
	renderqueue = &rqueue;
}


} // namespace logic
