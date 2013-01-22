/*
 * inputdevice.cpp
 *
 *  Created on: 22.1.2013
 *      Author: akin
 */

#include "inputdevice.hpp"

namespace input {

Device::~Device()
{
}

void Device::handleButton( uint32 id , float state )
{
	LOG->message( "%s:%i button %i at %d" , __FILE__ , __LINE__ , id , state );
}

void Device::handleCharacter( uint32 id , float state )
{
	LOG->message( "%s:%i char %i at %d" , __FILE__ , __LINE__ , id , state );
}

void Device::handleMove( uint32 id , float x , State state )
{
	LOG->message( "%s:%i move %i at %d state %i" , __FILE__ , __LINE__ , id , x , state );
}

void Device::handleMove( uint32 id , float x , float y , State state )
{
	LOG->message( "%s:%i move %i at %d,%d state %i" , __FILE__ , __LINE__ , id , x , y , state );
}

void Device::handleMove( uint32 id , float x , float y , float z , State state )
{
	LOG->message( "%s:%i move %i at %d,%d,%d state %i" , __FILE__ , __LINE__ , id , x , y , z , state );
}

} // namespace input 
