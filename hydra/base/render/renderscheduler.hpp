/*
 * RENDERQUEUE_HPP_.hpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#ifndef RENDERSCHEDULER_HPP_
#define RENDERSCHEDULER_HPP_

#include <stdtypes>
#include <uthread>
#include <deque>
#include "renderthread.hpp"

namespace render {

class Scheduler
{
private:
	typedef std::deque< ThreadPtr > RenderQue;

	std::mutex mutex;
	std::condition_variable condition;
	RenderQue queue;

	std::atomic<int> flags;

	bool stillRemaining();
public:
	Scheduler();
	~Scheduler();

	// queue stuff, that is immediately runnable, tries to run, until run finishes.
	// render sthread itself is responsible for locks et al.
	void add( ThreadPtr& thread );

	// indicate 'done' from logic
	void finish();

	// run interface
	void start();
};

} // namespace render
#endif // RENDERSCHEDULER_HPP_
