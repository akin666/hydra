/*
 * RENDERQUEUE_HPP_.hpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#ifndef RENDERQUEUE_HPP_
#define RENDERQUEUE_HPP_

#include <protothread>

namespace render {

class Queue
{
public:
	Queue();
	~Queue();

	// queue stuff, that is immediately runnable, tries to render, until run finishes.
	// proto itself is responsible for locks et al.
	void add( Protothread *thread );

	// indicate 'done' from logic
	void finished();

	// run interface
	void run();
};

} // namespace render
#endif // RENDERQUEUE_HPP_
