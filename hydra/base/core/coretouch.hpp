/*
 * coretouch.hpp
 *
 *  Created on: 30.1.2013
 *      Author: akin
 */

#ifndef CORETOUCH_HPP_
#define CORETOUCH_HPP_

#include "corecommon.hpp"
#include <signal.h>

namespace core {

class Touch
{
public:
	typedef std::shared_ptr<Touch> Ptr;
	typedef std::weak_ptr<Touch> WeakPtr;
	typedef std::map<int , Ptr> Map;
public:
	Touch();
	virtual ~Touch();

	signal::Signal4<int , float , float , TouchState> move;
};

} // namespace core 
#endif // CORETOUCH_HPP_ 
