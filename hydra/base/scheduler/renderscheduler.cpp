/*
 * RENDERSCHEDULER.cpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#include "renderscheduler.hpp"

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

void Scheduler::add( Protothread::Ptr& thread )
{
	std::lock_guard<std::mutex> lock(mutex);
	queue.push_back( thread );
	condition.notify_one();
}

void Scheduler::finish()
{
	if( (flags & RENDERSCHEDULER_QUIT) != 0 )
	{
		// already finished, cannot finish twice.
		return;
	}

	flags |= RENDERSCHEDULER_QUIT;
	condition.notify_one();
}


bool Scheduler::stillRemaining()
{
	std::lock_guard<std::mutex> lock(mutex);
	return !queue.empty();
}

void Scheduler::start()
{
	flags &= ~RENDERSCHEDULER_QUIT;

	Protothread::Ptr current;

	// Active state
	// stuff still coming
	while( (flags & RENDERSCHEDULER_QUIT) != 0 )
	{
		// Current should be pure at the beginning of the loop, dirty data confuses the loop.
		current.reset();
		{
			// Block till we get new data OR till we get message that no more threads are coming in
			std::unique_lock<std::mutex> lock(mutex);;
			while( queue.empty() && ( (flags & RENDERSCHEDULER_QUIT) != 0 ) )
			{
				condition.wait(lock);
			}
			if( !queue.empty() )
			{
				current = queue.front();
				queue.pop_front();
			}
		}
		// If we have a live thread, when we get here, run it
		if( current )
		{
			// If the thread does not finish, it goes to the end of renderlist.
			if( current->run() )
			{
				add( current );
			}
		}
	}

	// Passive state
	// No more stuff coming in, cleanup the queue
	while( stillRemaining() )
	{
		current.reset();
		{
			// We, (bit paranoidically) try to get data out
			std::lock_guard<std::mutex> lock(mutex);
			if( !queue.empty() )
			{
				current = queue.front();
				queue.pop_front();
			}
		}
		// If we have a live thread, when we get here, run it
		if( current )
		{
			// If the thread does not finish, it goes to the end of renderlist.
			if( current->run() )
			{
				add( current );
			}
		}
	}
}

} // namespace render
