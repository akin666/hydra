/*
 * applicationlistener.cpp2
 *
 *  Created on: 17.1.2013
 *      Author: akin
 */

#include "listenerapplication.hpp"
#include <log>

namespace listener {

Application::Application()
{
}

Application::~Application()
{
}

// Initializing
void Application::processArgs( int argc , char *argv[] )
{
	LOG->message( "%s:%i processargs " , __FILE__ , __LINE__ );
}

bool Application::initialize()
{
	LOG->message( "%s:%i init " , __FILE__ , __LINE__ );
	return false;
}

// Commands.
void Application::suspend()
{
	LOG->message( "%s:%i suspend " , __FILE__ , __LINE__ );
}

void Application::resume()
{
	LOG->message( "%s:%i resume " , __FILE__ , __LINE__ );
}

void Application::exit()
{
	LOG->message( "%s:%i exit " , __FILE__ , __LINE__ );
}

void Application::restart()
{
	LOG->message( "%s:%i restart " , __FILE__ , __LINE__ );
}

void Application::minimize()
{
	LOG->message( "%s:%i minimize " , __FILE__ , __LINE__ );
}

void Application::maximize()
{
	LOG->message( "%s:%i maximize " , __FILE__ , __LINE__ );
}

void Application::windowed()
{
	LOG->message( "%s:%i windowed " , __FILE__ , __LINE__ );
}

void Application::fullscreened()
{
	LOG->message( "%s:%i fullscreen " , __FILE__ , __LINE__ );
}

void Application::lostFocus()
{
	LOG->message( "%s:%i lostfocus " , __FILE__ , __LINE__ );
}

void Application::memoryWarning( uint level )
{
	LOG->message( "%s:%i memorywarning %i " , __FILE__ , __LINE__ , level );
}

void Application::saveState()
{
	LOG->message( "%s:%i savestate " , __FILE__ , __LINE__ );
}

// App exception handling
void Application::handleException( std::exception& e )
{
	LOG->message( "%s:%i Exception! %s " , __FILE__ , __LINE__ , e.what() );
}

void Application::handleEllipsisException()
{
	LOG->message( "%s:%i ellipsis exception! " , __FILE__ , __LINE__ );
}

} // listener
