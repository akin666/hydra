/*
 * RENDERQUEUE_HPP_.hpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#ifndef RENDERSCHEDULER_HPP_
#define RENDERSCHEDULER_HPP_

#include <stdtypes>
#include <tque>

namespace render {

class Thread;
class Scheduler
{
private:
	typedef TQue<Thread *> RendererQue;
	RendererQue queue;
	std::atomic<int> flags;
public:
	Scheduler();
	~Scheduler();

	// queue stuff, that is immediately runnable, tries to run, until run finishes.
	// render sthread itself is responsible for locks et al.
	void add( Thread& thread );

	// indicate 'done' from logic
	void finish();

	// run interface
	void start();
};

} // namespace render
#endif // RENDERSCHEDULER_HPP_
