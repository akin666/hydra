/*
 * renderthreaad.hpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#ifndef RENDERTHREAD_HPP_
#define RENDERTHREAD_HPP_

#include <protothread>
#include <stdtypes>

namespace render {

class Thread : public Protothread
{
public:
	Thread();
	virtual ~Thread();
};

typedef std::shared_ptr<Thread> ThreadPtr;
typedef std::vector<ThreadPtr> ThreadSet;

} // namespace render
#endif // RENDERTHREAD_HPP_
