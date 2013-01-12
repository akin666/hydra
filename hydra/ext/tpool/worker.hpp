
#ifndef TPOOL_WORKER_H_
#define TPOOL_WORKER_H_

#include <tque>
#include <thread>
#include <protothread>
#include <stdtypes>

namespace tpool {

typedef TQue<Protothread> ProtoQueue;
typedef std::shared_ptr<ProtoQueue> ProtoQueuePtr;

class Worker
{
protected:
	// shared queue with other workers.
	ProtoQueuePtr queu;
	std::thread *thread;

	std::mutex mutex;
	std::condition_variable condition;
	std::atomic<bool> going;
public:
	Worker();
	~Worker();

	void init( ProtoQueuePtr& wqueu );

	void operator()();

	void terminate();
};

typedef std::shared_ptr<Worker> WorkerPtr;

} // namespace tpool
#endif // TPOOL_WORKER_H_
