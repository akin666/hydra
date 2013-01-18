/*
 * listenerjoystick.hpp
 *
 *  Created on: 19.1.2013
 *      Author: akin
 */

#ifndef LISTENERJOYSTICK_HPP_
#define LISTENERJOYSTICK_HPP_

#include "listenercommon.hpp"

namespace listener {

class Joystick
{
public:
	Joystick();
	virtual ~Joystick();

	virtual void handleJoystickMove( const int device , const float x , const float y );
	virtual void handleJoystickButton( const int device , const Button button , const float state );
};

} // namespace listener 
#endif // LISTENERJOYSTICK_HPP_ 
