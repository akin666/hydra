/*
 * RENDERQUEUE_HPP_.hpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#ifndef RENDERQUEUE_HPP_
#define RENDERQUEUE_HPP_

#include <stdtypes>
#include <tque>

namespace render {

class Thread;
class Queue
{
private:
	typedef TQue<Thread *> RendererQue;
	RendererQue queue;
	std::atomic<int> flags;
public:
	Queue();
	~Queue();

	// queue stuff, that is immediately runnable, tries to run, until run finishes.
	// render sthread itself is responsible for locks et al.
	void add( Thread *thread );

	// indicate 'done' from logic
	void finish();

	// run interface
	void start();
};

} // namespace render
#endif // RENDERQUEUE_HPP_
