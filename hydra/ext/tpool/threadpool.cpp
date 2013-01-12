
#include "threadpool.hpp"
#include <thread>
#include <stdexcept>

namespace tpool {

unsigned int ThreadPool::getHardwareThreadCount()
{
	return std::thread::hardware_concurrency();
}

ThreadPool::ThreadPool()
: worker_count( 2 )
{
}

ThreadPool::~ThreadPool()
{
}

void ThreadPool::initialize( unsigned int count )
{
	std::lock_guard<std::mutex> lock(mutex);
	worker_count = count;
	while( workers.size() < worker_count )
	{
		WorkerPtr ptr( new Worker );
		workers.push_back( ptr );
		ptr->init( data );
	}
}

void ThreadPool::kill()
{
	std::lock_guard<std::mutex> lock(mutex);
	for( auto workerptr : workers )
	{
		workerptr->terminate();
	}
	workers.clear();
}

int ThreadPool::getWorkerCount()
{
	return worker_count;
}

void ThreadPool::schedule( WorkPtr& work )
{
	data.push( work );
}

} // tpool


