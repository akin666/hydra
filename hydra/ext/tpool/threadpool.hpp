
#ifndef TPOOL_THREADPOOL_H_
#define TPOOL_THREADPOOL_H_

#include <work>
#include <uthread>
#include "worker.hpp"

namespace tpool
{

class ThreadPool
{
private:
	std::mutex mutex;

	WorkQue data;
	typedef std::vector<WorkerPtr> WorkerSet;
	WorkerSet workers;
	int worker_count;
public:
	ThreadPool();
	~ThreadPool();

	static unsigned int getHardwareThreadCount();

	void initialize( unsigned int count );

	void schedule( WorkPtr& work );

	int getWorkerCount();

	void kill();
};

} // namespace tpool
#endif // TPOOL_THREADPOOL_H_
