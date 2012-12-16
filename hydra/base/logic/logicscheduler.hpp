/*
 * logicscheduler.hpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#ifndef LOGICSCHEDULER_HPP_
#define LOGICSCHEDULER_HPP_

#include "logicthread.hpp"
#include "../render/renderqueue.hpp"
#include <uthread>

namespace logic {

class Thread;
class Scheduler
{
protected:
	std::mutex mutex;
	std::mutex deepMutex;

	ThreadSet threads;
	ThreadSet added;
public:
	Scheduler();
	~Scheduler();

	// queue stuff, that is runnable
	// thread itself is responsible for locks et al.
	void queue( Thread *thread );

	// spawn protos interface
	void start( render::Queue& target );
};

} // namespace logic
#endif // LOGICSCHEDULER_HPP_
