/*
 * RENDERQUEUE.cpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#include "renderqueue.hpp"
#include "renderrenderer.hpp"

#define RENDERQUEUE_NONE 0x0
#define RENDERQUEUE_QUIT 0x1

namespace render {

Queue::Queue()
: flags(RENDERQUEUE_NONE)
{
}

Queue::~Queue()
{
}

void Queue::add( Renderer* thread )
{
	if( thread == nullptr )
	{
		return;
	}
	queue.push( thread );
}

void Queue::finish()
{
	if( (flags & RENDERQUEUE_QUIT) != 0 )
	{
		// already finished, cannot finish twice.
		return;
	}
	flags |= RENDERQUEUE_QUIT;
	queue.push( nullptr );
}

void Queue::start()
{
	flags &= ~RENDERQUEUE_QUIT;

	// nullptr is like 'game over' after we hit it, we know that end is near.
	// there should not be 2 of them in que
	Renderer *current = nullptr;
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
