/*
 * corejoystick.hpp
 *
 *  Created on: 29.1.2013
 *      Author: akin
 */

#ifndef COREJOYSTICK_HPP_
#define COREJOYSTICK_HPP_

#include "corecommon.hpp"
#include <signal.h>

namespace core {

class Joystick
{
public:
	typedef std::shared_ptr<Joystick> Ptr;
	typedef std::weak_ptr<Joystick> WeakPtr;
	typedef std::map<int , Ptr> Map;
public:
	Joystick();
	~Joystick();

	signal::Signal2<float , float> move;
	signal::Signal2<int , ButtonState> button;
	signal::Signal1<float> wheel;
	signal::Signal1<bool> connected;
};

} // namespace core 
#endif // COREJOYSTICK_HPP_ 
