/*
 * coretouch.hpp
 *
 *  Created on: 30.1.2013
 *      Author: akin
 */

#ifndef CORETOUCH_HPP_
#define CORETOUCH_HPP_

#include <commontypes.h>
#include <signal.h>

namespace core {

class Touch
{
public:
	enum State{ CANCELLED = 0 , STARTED = 1 , ENDED = 2 };

	typedef std::shared_ptr<Touch> Ptr;
	typedef std::weak_ptr<Touch> WeakPtr;
	typedef std::map<int , Ptr> Map;
public:
	Touch();
	virtual ~Touch();

	signal::Signal4<int , float , float , State> move;
};

} // namespace core 
#endif // CORETOUCH_HPP_ 
