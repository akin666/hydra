
#ifndef TPOOL_THREADPOOL_H_
#define TPOOL_THREADPOOL_H_

#include <work>
#include "worker.hpp"

namespace tpool
{

class ThreadPool
{
protected:
	WorkQue data;
	Worker *workers;
	int worker_count;
public:
	ThreadPool();
	~ThreadPool();

	static unsigned int getHardwareThreadCount();

	void initialize( unsigned int count );

	void schedule( Work *work );

	int getWorkerCount();

	void kill();
};

} // namespace tpool
#endif // TPOOL_THREADPOOL_H_
