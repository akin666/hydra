/*
 * listenermouse.cpp
 *
 *  Created on: 19.1.2013
 *      Author: akin
 */

#include "listenermouse.hpp"
#include <commontypes.h>

namespace listener {

Mouse::Mouse()
{
}

Mouse::~Mouse()
{
}

void Mouse::handleMouseMove( const int device , const float x , const float y )
{
	LOG->message( "%s:%i mouse %i at %dx%d" , __FILE__ , __LINE__ , device , x , y );
}

void Mouse::handleMouseButton( const int device , const Button button , const float state )
{
	LOG->message( "%s:%i mouse %i state %i went %d" , __FILE__ , __LINE__ , device , button , state );
}

void Mouse::handleMouseButtonAction( const int device , const Button button )
{
	LOG->message( "%s:%i mouse %i action %i went %d" , __FILE__ , __LINE__ , device , button );
}

void Mouse::handleMouseWheel( const int device , const float val )
{
	LOG->message( "%s:%i mouse %i wheel %d" , __FILE__ , __LINE__ , device , val );
}

} // namespace listener 
