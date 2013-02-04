/*
 * corecontext.cpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#include "corecontext.hpp"

namespace core {

const std::string Context::PATH( "core" );

Context::Context()
{
}

Context::~Context()
{
}

// App exception handling
void Context::handleException( std::exception& e )
{
}

void Context::handleEllipsisException()
{
}

void Context::get( Joystick::Ptr& ptr , int number )
{
}

void Context::get( Keyboard::Ptr& ptr , int number )
{
}

void Context::get( Mouse::Ptr& ptr , int number )
{
}

void Context::get( Touch::Ptr& ptr , int number )
{
}

int Context::getJoystickCount()
{
	return 0;
}

int Context::getKeyboardCount()
{
	return 0;
}

int Context::getMouseCount()
{
	return 0;
}

int Context::getTouchCount()
{
	return 0;
}

} // namespace core 
