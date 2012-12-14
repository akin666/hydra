/*
 * RENDERQUEUE_HPP_.hpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#ifndef RENDERQUEUE_HPP_
#define RENDERQUEUE_HPP_

namespace render {

class Renderer;
class Queue
{
public:
	Queue();
	~Queue();

	// queue stuff, that is immediately runnable, tries to render, until run finishes.
	// renderer itself is responsible for locks et al.
	void add( Renderer *thread );

	// indicate 'done' from logic
	void finished();

	// run interface
	void run();
};

} // namespace render
#endif // RENDERQUEUE_HPP_
