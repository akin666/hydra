/*
 * listenerjoystick.cpp
 *
 *  Created on: 19.1.2013
 *      Author: akin
 */

#include "listenerjoystick.hpp"
#include <commontypes.h>

namespace listener
{

Joystick::Joystick()
{
}

Joystick::~Joystick()
{
}

void Joystick::handleJoystickMove( const int device , const float x , const float y )
{
	LOG->message( "%s:%i joystick %i at %dx%d" , __FILE__ , __LINE__ , device , x , y );
}

void Joystick::handleJoystickButton( const int device , const Button button , const float state )
{
	LOG->message( "%s:%i joystick %i action %i went %d" , __FILE__ , __LINE__ , device , button , state );
}

} // namespace listener 
