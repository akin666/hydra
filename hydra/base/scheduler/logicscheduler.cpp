/*
 * logicscheduler.cpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#include "logicscheduler.hpp"
#include <commontypes.h>
#include <tpool/threadpool.hpp>

namespace logic {

Scheduler::Scheduler()
{
}

Scheduler::~Scheduler()
{
}

void Scheduler::queue( Protothread::Ptr& thread )
{
	std::lock_guard<std::mutex> lock( mutex );
	added.push_back( thread );
}

void Scheduler::reset()
{
}

void Scheduler::start( )
{
	std::lock_guard<std::mutex> lock( deepMutex );

	// Add new threads into set
	{
		std::lock_guard<std::mutex> lock( mutex );
		for( auto& thread : added )
		{
			threads.push_back( thread );
		}
		added.clear();
	}

	// Add protos as work, for workers to process. Remove from the list if that proto is done.
	// Clear dead protos out
	{
		auto iter = threads.begin();
		while( iter != threads.end() )
		{
			if( (*iter)->isFinished() )
			{
				iter = threads.erase( iter );
				continue;
			}

			(*iter)->restart();
			++iter;
		}
	}

	// push them to the workpool..
	getSingleton<tpool::ThreadPool>()->schedule( threads );
}

} // namespace logic
