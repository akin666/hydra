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
#include <protothread>

namespace render {

class Scheduler
{
public:
	typedef std::shared_ptr<Scheduler> Ptr;
	typedef std::weak_ptr<Scheduler> WeakPtr;
private:
	typedef std::deque< Protothread::Ptr > RenderQue;

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
	void add( Protothread::Ptr& thread );

	// indicate 'done' from logic
	void finish();

	// indicate that that this should reset..
	void reset();

	// run interface
	void start();
};

} // namespace render
#endif // RENDERSCHEDULER_HPP_
