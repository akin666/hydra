/*
 * logicscheduler.cpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#include "logicscheduler.hpp"
#include "logicthread.hpp"

namespace logic {

Scheduler::Scheduler( render::Scheduler& target )
: target( target )
{
}

Scheduler::~Scheduler()
{
}

void Scheduler::queue( Thread& thread )
{
	std::lock_guard<std::mutex> lock( mutex );
	added.push_back( &thread );
}

void Scheduler::start( )
{
	std::lock_guard<std::mutex> lock( deepMutex );

	// Add new threads into set
	{
		for( ThreadSet::iterator iter = added.begin() ; iter != added.end() ; ++iter )
		{
			threads.push_back( *iter );
			(*iter)->set( target );
			(*iter)->set( *this );
		}

		added.clear();
		std::lock_guard<std::mutex> lock( mutex );
	}

	// Add protos as work, for workers to process. Remove from the list if that proto is done.
	// TODO! add real threading
	for( ThreadSet::iterator iter = threads.begin() ; iter != threads.end() ; ++iter )
	{
		while( !(*iter)->run() )
		{
			// kill
			iter = threads.erase( iter );
			if( iter == threads.end() )
			{
				return;
			}
		}
	}
}

} // namespace logic