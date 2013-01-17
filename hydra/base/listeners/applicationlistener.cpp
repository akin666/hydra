/*
 * applicationlistener.cpp
 *
 *  Created on: 17.1.2013
 *      Author: akin
 */

#include "applicationlistener.hpp"

#include <log>

ApplicationListener::ApplicationListener()
{
}

ApplicationListener::~ApplicationListener()
{
}

// Initializing
void ApplicationListener::processArgs( int argc , char *argv[] )
{
	LOG->message( "%s:%i processargs " , __FILE__ , __LINE__ );
}

bool ApplicationListener::initialize()
{
	LOG->message( "%s:%i init " , __FILE__ , __LINE__ );
	return false;
}

// Commands.
void ApplicationListener::suspend()
{
	LOG->message( "%s:%i suspend " , __FILE__ , __LINE__ );
}

void ApplicationListener::resume()
{
	LOG->message( "%s:%i resume " , __FILE__ , __LINE__ );
}

void ApplicationListener::exit()
{
	LOG->message( "%s:%i exit " , __FILE__ , __LINE__ );
}

void ApplicationListener::restart()
{
	LOG->message( "%s:%i restart " , __FILE__ , __LINE__ );
}

void ApplicationListener::minimize()
{
	LOG->message( "%s:%i minimize " , __FILE__ , __LINE__ );
}

void ApplicationListener::maximize()
{
	LOG->message( "%s:%i maximize " , __FILE__ , __LINE__ );
}

void ApplicationListener::windowed()
{
	LOG->message( "%s:%i windowed " , __FILE__ , __LINE__ );
}

void ApplicationListener::fullscreened()
{
	LOG->message( "%s:%i fullscreen " , __FILE__ , __LINE__ );
}

void ApplicationListener::lostFocus()
{
	LOG->message( "%s:%i lostfocus " , __FILE__ , __LINE__ );
}

void ApplicationListener::memoryWarning( uint level )
{
	LOG->message( "%s:%i memorywarning %i " , __FILE__ , __LINE__ , level );
}

void ApplicationListener::saveState()
{
	LOG->message( "%s:%i savestate " , __FILE__ , __LINE__ );
}

// App exception handling
void ApplicationListener::handleException( std::exception& e )
{
	LOG->message( "%s:%i Exception! %s " , __FILE__ , __LINE__ , e.what() );
}

void ApplicationListener::handleEllipsisException()
{
	LOG->message( "%s:%i ellipsis exception! " , __FILE__ , __LINE__ );
}
