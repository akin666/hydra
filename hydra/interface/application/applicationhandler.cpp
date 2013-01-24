/*
 * applicationhandler.cpp
 *
 *  Created on: 24.1.2013
 *      Author: akin
 */

#include "applicationhandler.hpp"
#include <commontypes.h>

namespace application {

Handler::Handler()
{
}

Handler::~Handler()
{
}

// Commands.
void Handler::suspend()
{
	LOG->message( "%s:%i suspend " , __FILE__ , __LINE__ );
}

void Handler::resume()
{
	LOG->message( "%s:%i resume " , __FILE__ , __LINE__ );
}

void Handler::exit()
{
	LOG->message( "%s:%i exit " , __FILE__ , __LINE__ );
}

void Handler::restart()
{
	LOG->message( "%s:%i restart " , __FILE__ , __LINE__ );
}

void Handler::minimize()
{
	LOG->message( "%s:%i minimize " , __FILE__ , __LINE__ );
}

void Handler::maximize()
{
	LOG->message( "%s:%i maximize " , __FILE__ , __LINE__ );
}

void Handler::windowed()
{
	LOG->message( "%s:%i windowed " , __FILE__ , __LINE__ );
}

void Handler::fullscreened()
{
	LOG->message( "%s:%i fullscreen " , __FILE__ , __LINE__ );
}

void Handler::lostFocus()
{
	LOG->message( "%s:%i lostfocus " , __FILE__ , __LINE__ );
}

void Handler::memoryWarning( uint level )
{
	LOG->message( "%s:%i memorywarning %i " , __FILE__ , __LINE__ , level );
}

void Handler::saveState()
{
	LOG->message( "%s:%i savestate " , __FILE__ , __LINE__ );
}

// App exception handling
void Handler::handleException( std::exception& e )
{
	LOG->message( "%s:%i Exception! %s " , __FILE__ , __LINE__ , e.what() );
}

void Handler::handleEllipsisException()
{
	LOG->message( "%s:%i ellipsis exception! " , __FILE__ , __LINE__ );
}

} // namespace application 
