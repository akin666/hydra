/*
 * audiocontext.cpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#include "audiocontext.hpp"

namespace audio {

Context::Context( input::Manager::Ptr& inputmanager )
: inputmanager( inputmanager )
{
}

Context::~Context()
{
}

} // namespace audio 
