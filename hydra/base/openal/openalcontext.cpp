/*
 * audioalcontext.cpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#include "openalcontext.hpp"

namespace openal {

Context::Context( input::Manager::Ptr& inputmanager )
: audio::Context( inputmanager )
{
}

Context::~Context()
{
}

bool Context::initialize( Json::ValuePtr& config )
{
	return false;
}

} // namespace openal
