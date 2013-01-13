/*
 * logicscheduler.cpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#include "logicscheduler.hpp"
#include "logicthread.hpp"
#include <commontypes.h>
#include <tpool/threadpool.hpp>

namespace logic {

Scheduler::Scheduler( render::Scheduler& target )
: target( target )
{
}

Scheduler::~Scheduler()
{
}

void Scheduler::queue( ProtothreadPtr& thread )
{
	std::lock_guard<std::mutex> lock( mutex );

	auto logicThread = dynamic_cast<logic::Thread*>( thread.get() );
	if( logicThread == nullptr )
	{
		LOG->error("%s:%i Cannot put random protothreads into logic queu." , __FILE__ , __LINE__ );
		return;
	}

	added.push_back( thread );
}

void Scheduler::start( )
{
	std::lock_guard<std::mutex> lock( deepMutex );

	// Add new threads into set
	{
		for( auto thread : added )
		{
			auto logicThread = dynamic_cast<logic::Thread*>( thread.get() );
			if( logicThread != nullptr )
			{
				threads.push_back( thread );
				logicThread->set( target );
				logicThread->set( *this );
			}
		}

		added.clear();
		std::lock_guard<std::mutex> lock( mutex );
	}

	// Add protos as work, for workers to process. Remove from the list if that proto is done.
	// TODO! add real threading
	// Clear dead protos out
	{
		auto iter = threads.begin();
		while( iter != threads.end() )
		{
			if( !(*iter)->isRunning() )
			{
				iter = threads.erase( iter );
			}
			else
			{
				iter++;
			}
		}
	}

	// push them to the workpool..
	getSingleton<tpool::ThreadPool>()->schedule( threads );
}

} // namespace logic
