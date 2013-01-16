// todoo
/*
 * inputlistener.cpp
 *
 *  Created on: 18.7.2011
 *      Author: akin
 */

#include "inputlistener.h"

#include <log>

InputListener::InputListener()
{
}

InputListener::~InputListener()
{
}

void InputListener::handleMouseMove( const int device , const float x , const float y )
{
	LOG->message( "%s:%i mouse %i at %dx%d" , device , x , y );
}

void InputListener::handleMouseButton( const int device , const Button button , const float state )
{
	LOG->message( "%s:%i mouse %i state %i went %d" , device , button , state );
}

void InputListener::handleMouseButtonAction( const int device , const Button button )
{
	LOG->message( "%s:%i mouse %i action %i went %d" , device , button );
}

void InputListener::handleMouseWheel( const int device , const float val )
{
	LOG->message( "%s:%i mouse %i wheel %d" , device , val );
}

void InputListener::handleJoystickMove( const int device , const float x , const float y )
{
	LOG->message( "%s:%i joystick %i at %dx%d" , device , x , y );
}

void InputListener::handleJoystickButton( const int device , const Button button , const float state )
{
	LOG->message( "%s:%i joystick %i action %i went %d" , device , button , state );
}

void InputListener::handleKeyboard( const int device , const unsigned int key , const float state )
{
	LOG->message( "%s:%i keyboard %i key %i went %d" , device , key , state );
}

void InputListener::handleKeyboardCharacter( const int device , const unsigned int key , const float state )
{
	LOG->message( "%s:%i keyboard %i character %i went %d" , device , key , state );
}

void InputListener::handleTouch( const int device , const float x , const float y , const State state , const float value )
{
	LOG->message( "%s:%i touch %i at %dx%d with state %i value %d" , device , x , y , state , value );
}
