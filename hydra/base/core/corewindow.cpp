/*
 * systemwindow.cpp
 *
 *  Created on: 23.1.2013
 *      Author: akin
 */

#include "corewindow.hpp"

namespace core {

Window::Window()
{
}

Window::~Window()
{
}

void Window::get( const String8& name , input::Source::Ptr& ptr )
{
}

void Window::get( input::Mode mode , input::Source::Ptr& ptr )
{
}

void Window::get( input::Type type , input::Source::Ptr& ptr )
{
}

void Window::clean()
{
}

void Window::get( input::Mode& mode ) const
{
}

void Window::get( input::Type& mode ) const
{
}

void Window::get( StringSet& names ) const
{
}

} // namespace core
