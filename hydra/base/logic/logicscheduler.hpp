/*
 * logicscheduler.hpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#ifndef LOGICSCHEDULER_HPP_
#define LOGICSCHEDULER_HPP_

#include "logicthread.hpp"
#include "../render/renderscheduler.hpp"
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

	render::Scheduler& target;
public:
	Scheduler( render::Scheduler& target );
	~Scheduler();

	// queue stuff, that is runnable
	// thread itself is responsible for locks et al.
	void queue( Thread& thread );

	// spawn protos interface
	void start();
};

} // namespace logic
#endif // LOGICSCHEDULER_HPP_
