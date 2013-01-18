/*
 * listenerkeyboard.hpp
 *
 *  Created on: 19.1.2013
 *      Author: akin
 */

#ifndef LISTENERKEYBOARD_HPP_
#define LISTENERKEYBOARD_HPP_

#include "listenercommon.hpp"

namespace listener {

class Keyboard
{
public:
	Keyboard();
	virtual ~Keyboard();

	virtual void handleKeyboard( const int device , const unsigned int key , const float state );
	virtual void handleKeyboardCharacter( const int device , const unsigned int key , const float state );
	virtual void handleTouch( const int device , const float x , const float y , const State state , const float value );
};

} // namespace listener 
#endif // LISTENERKEYBOARD_HPP_ 
