
#include "worker.hpp"
#include <iostream>
#include <stdexcept>


namespace tpool {

Worker::Worker()
: thread( nullptr )
, going( false )
{
}

Worker::~Worker()
{
	delete thread;
	thread = nullptr;
}

void Worker::init( ProtoQueuePtr& wqueu )
{
	if( thread == nullptr )
	{
		// This Sync of worker thread, and initializer, ensures that
		// the worker really is initialized after exiting this function.
		// ! If this is not done, the workers probably will get initialized
		// much later..
		std::unique_lock<std::mutex> lock(mutex);
		if( thread != nullptr )
		{
			return;
		}

		queu = wqueu;
		going = false;
		thread = new std::thread( std::ref(*this) );

		// Ensure that the function returns _after_ the thread has fully initialized
		while( !going )
		{
			condition.wait(lock);
		}
	}
	else
	{
		throw std::runtime_error("Thread is already running.");
	}
}

void Worker::operator()()
{
	// Thread initialization/volatile/sync block
	{
		std::lock_guard<std::mutex> lock(mutex);

		// Do initialization here!

		// Initialization done.
		going = true;
		condition.notify_one();
	}

	ProtothreadPtr current;
	while( going )
	{
		// keep it clean.
		current.reset();

		// Pop front. or wait something to pop.
		queu->pop( current );
		if( current )
		{
			// Is the thread done?
			if( current->isRunning() )
			{
				if( !current->run() )
				{
					queu->push( current );
				}
			}
		}
	}

	// Thread dying/sync block
	{
		std::lock_guard<std::mutex> lock(mutex);

		// Do KILLING here.

		// Initialization done.
		going = true;
		condition.notify_one();
	}
}

void Worker::terminate()
{
	if( going && thread != nullptr )
	{
		std::unique_lock<std::mutex> lock(mutex);
		going = false;

		while( !going )
		{
			condition.wait(lock);
		}

		delete thread;
		thread = nullptr;
	}
}

} // tpool
