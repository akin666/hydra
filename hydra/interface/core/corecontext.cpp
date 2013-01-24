/*
 * corecontext.cpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#include "corecontext.hpp"

namespace core {

Context::Context( application::Manager::Ptr& applicationmanager , input::Manager::Ptr& inputmanager )
: applicationmanager( applicationmanager )
, inputmanager( inputmanager )
{
}

Context::~Context()
{
}

} // namespace core 
