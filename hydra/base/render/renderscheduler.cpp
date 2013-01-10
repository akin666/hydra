/*
 * RENDERSCHEDULER.cpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#include "renderscheduler.hpp"
#include "renderthread.hpp"

#define RENDERSCHEDULER_NONE 0x0
#define RENDERSCHEDULER_QUIT 0x1

namespace render {

Scheduler::Scheduler()
: flags(RENDERSCHEDULER_NONE)
{
}

Scheduler::~Scheduler()
{
}

void Scheduler::add( Thread& thread )
{
	queue.push( &thread );
}

void Scheduler::finish()
{
	if( (flags & RENDERSCHEDULER_QUIT) != 0 )
	{
		// already finished, cannot finish twice.
		return;
	}
	flags |= RENDERSCHEDULER_QUIT;
	queue.push( nullptr );
}

void Scheduler::start()
{
	flags &= ~RENDERSCHEDULER_QUIT;

	// nullptr is like 'game over' after we hit it, we know that end is near.
	// there should not be 2 of them in que
	Thread *current = nullptr;
	while( (current = queue.pop()) != nullptr )
	{
		// recycle thread, till run returns false
		if( current->run() )
		{
			queue.push( current );
		}
	}
	// There can be only one nullptr in que, pop rest of the stuff out.
	while( (current = queue.pop( RendererQue::RETURN_NULL_IF_EMPTY )) != nullptr )
	{
		// recycle thread, till run returns false
		if( current->run() )
		{
			queue.push( current );
		}
	}
}

} // namespace render
