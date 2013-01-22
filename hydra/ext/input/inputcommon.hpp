/*
 * inputcommon.hpp
 *
 *  Created on: 22.1.2013
 *      Author: akin
 */

#ifndef INPUTCOMMON_HPP_
#define INPUTCOMMON_HPP_

#include <commontypes.h>

namespace input {

enum State
{
	BEGIN,
	END,
	MOVED,
	CANCELLED
};

enum Mode
{
	BUTTON 		= 0x0001,
	CHARACTER	= 0x0002,
	MOVE		= 0x0004,
	MOVE2D		= 0x0008,
	MOVE3D		= 0x0010
};

enum Type
{
	ANY,
	KEYBOARD,
	JOYSTICK,
	MOUSE,
	TOUCH
};

} // input


#endif // INPUTCOMMON_HPP_ 
