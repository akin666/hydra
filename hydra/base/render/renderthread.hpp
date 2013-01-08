/*
 * renderthreaad.hpp
 *
 *  Created on: 14.12.2012
 *      Author: akin
 */

#ifndef RENDERTHREAD_HPP_
#define RENDERTHREAD_HPP_

#include <protothread>

namespace render {

class Thread : public Protothread
{
public:
	Thread();
	virtual ~Thread();
};

} // namespace render
#endif // RENDERTHREAD_HPP_
