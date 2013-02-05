/*
 * coremouse.hpp
 *
 *  Created on: 29.1.2013
 *      Author: akin
 */

#ifndef COREMOUSE_HPP_
#define COREMOUSE_HPP_

#include "corecommon.hpp"
#include <signal.h>

namespace core {

class Mouse
{
public:
	typedef std::shared_ptr<Mouse> Ptr;
	typedef std::weak_ptr<Mouse> WeakPtr;
	typedef std::map<int , Ptr> Map;
public:
	Mouse();
	~Mouse();

	signal::Signal2<float , float> move;
	signal::Signal2<int , ButtonState> button;
	signal::Signal1<float> wheel;
	signal::Signal1<bool> connected;
};

} // namespace core 
#endif // COREMOUSE_HPP_ 
