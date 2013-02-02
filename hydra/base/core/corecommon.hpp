/*
 * corecommon.hpp
 *
 *  Created on: 22.1.2013
 *      Author: akin
 */

#ifndef CORECOMMON_HPP_
#define CORECOMMON_HPP_

#include <commontypes.h>

namespace core {

enum TouchState
{
	CANCELLED	= 0x0001,
	BEGIN 		= 0x0002,
	END 		= 0x0004,
	MOVED 		= 0x0008
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
	ANY			= 0x0001,
	KEYBOARD	= 0x0002,
	JOYSTICK	= 0x0004,
	MOUSE		= 0x0008,
	TOUCH		= 0x0010
};

enum ButtonState
{
	UP 			= 0 ,
	DOWN 		= 1
};

enum Button
{
	LEFT 		= 0 ,
	RIGHT 		= 1 ,
	MIDDLE 		= 2 ,
	EXTRA 		= 3
};

} // core

#endif // CORECOMMON_HPP_
