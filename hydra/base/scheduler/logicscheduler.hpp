/*
 * logicscheduler.hpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#ifndef LOGICSCHEDULER_HPP_
#define LOGICSCHEDULER_HPP_

#include <uthread>
#include <protothread>

namespace logic {

class Scheduler
{
public:
	typedef std::shared_ptr<Scheduler> Ptr;
	typedef std::weak_ptr<Scheduler> WeakPtr;
private:
	std::mutex mutex;
	std::mutex deepMutex;

	ProtothreadSet threads;
	ProtothreadSet added;
public:
	Scheduler();
	~Scheduler();

	// queue stuff, that is runnable
	// thread itself is responsible for locks et al.
	void queue( Protothread::Ptr& thread );

	// spawn protos interface
	void start();
};

} // namespace logic
#endif // LOGICSCHEDULER_HPP_
