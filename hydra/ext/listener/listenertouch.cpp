/*
 * listenertouch.cpp
 *
 *  Created on: 19.1.2013
 *      Author: akin
 */

#include "listenertouch.hpp"
#include <commontypes.h>

namespace listener
{

Touch::Touch()
{
}

Touch::~Touch()
{
}

void Touch::handleTouchBegin( const int device , const float x , const float y )
{
	LOG->message( "%s:%i touch begin %i at %dx%d" , __FILE__ , __LINE__ , device , x , y );
}

void Touch::handleTouchMoved( const int device , const float x , const float y )
{
	LOG->message( "%s:%i touch moved %i at %dx%d" , __FILE__ , __LINE__ , device , x , y );
}

void Touch::handleTouchEnded( const int device , const float x , const float y )
{
	LOG->message( "%s:%i touch ended %i at %dx%d" , __FILE__ , __LINE__ , device , x , y );
}

void Touch::handleTouchCancelled( const int device , const float x , const float y )
{
	LOG->message( "%s:%i touch cancelled %i at %dx%d" , __FILE__ , __LINE__ , device , x , y );
}

} // namespace listener 
