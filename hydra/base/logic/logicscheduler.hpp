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

// forward declaration of hydra::main needed..
namespace hydra {
class Main;
}

namespace logic {

class Thread;
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

	hydra::Main& main;
public:
	Scheduler( hydra::Main& main );
	~Scheduler();

	// queue stuff, that is runnable
	// thread itself is responsible for locks et al.
	void queue( ProtothreadPtr& thread );

	hydra::Main& accessMain();

	// spawn protos interface
	void start();
};

} // namespace logic
#endif // LOGICSCHEDULER_HPP_
