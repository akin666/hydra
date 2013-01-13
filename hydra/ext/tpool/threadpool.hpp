
#ifndef TPOOL_THREADPOOL_H_
#define TPOOL_THREADPOOL_H_

#include <protothread>
#include <uthread>
#include "worker.hpp"

namespace tpool {

class ThreadPool
{
private:
	std::mutex mutex;

	ProtoQueuePtr data;
	typedef std::vector<WorkerPtr> WorkerSet;
	WorkerSet workers;
	int worker_count;
public:
	ThreadPool();
	~ThreadPool();

	static unsigned int getHardwareThreadCount();

	bool initialize( unsigned int count );

	void schedule( ProtothreadPtr& work );
	void schedule( ProtothreadSet& set );

	int getWorkerCount();

	void kill();
};

} // namespace tpool
#endif // TPOOL_THREADPOOL_H_
