/*
 * listenerkeyboard.cpp
 *
 *  Created on: 19.1.2013
 *      Author: akin
 */

#include "listenerkeyboard.hpp"
#include <commontypes.h>

namespace listener {

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}

void Keyboard::handleKeyboard( const int device , const unsigned int key , const float state )
{
	LOG->message( "%s:%i keyboard %i key %i went %d" , __FILE__ , __LINE__ , device , key , state );
}

void Keyboard::handleKeyboardCharacter( const int device , const unsigned int key , const float state )
{
	LOG->message( "%s:%i keyboard %i character %i went %d" , __FILE__ , __LINE__ , device , key , state );
}

void Keyboard::handleTouch( const int device , const float x , const float y , const State state , const float value )
{
	LOG->message( "%s:%i touch %i at %dx%d with state %i value %d" , __FILE__ , __LINE__ , device , x , y , state , value );
}


} // namespace listener 
