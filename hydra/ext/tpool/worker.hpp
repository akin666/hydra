
#ifndef TPOOL_WORKER_H_
#define TPOOL_WORKER_H_

#include <tque>
#include <thread>
#include <work>

namespace tpool {

class Worker
{
protected:
	// shared queue with other workers.
	WorkQue *queu;
	std::thread *thread;

	std::mutex mutex;
	std::condition_variable condition;
	bool going;
public:
	Worker();
	~Worker();

	void init( WorkQue& wqueu );

	void operator()();

	void terminate();
};

} // namespace tpool
#endif // TPOOL_WORKER_H_
