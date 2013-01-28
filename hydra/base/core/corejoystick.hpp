/*
 * corejoystick.hpp
 *
 *  Created on: 29.1.2013
 *      Author: akin
 */

#ifndef COREJOYSTICK_HPP_
#define COREJOYSTICK_HPP_

#include <commontypes.h>
#include <signal.h>

namespace core {

class Joystick
{
public:
	enum State{ UP = 0 , DOWN = 1 };

	typedef std::shared_ptr<Joystick> Ptr;
	typedef std::weak_ptr<Joystick> WeakPtr;
public:
	Joystick();
	~Joystick();

	signal::Signal2<float , float> move;
	signal::Signal2<int , State> button;
	signal::Signal1<float> wheel;
};

} // namespace core 
#endif // COREJOYSTICK_HPP_ 
