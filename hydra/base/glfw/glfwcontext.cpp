/*
 * glfwcontext.cpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#include "glfwcontext.hpp"

namespace glfw {

Context::Context( application::Manager::Ptr& applicationmanager , input::Manager::Ptr& inputmanager )
: core::Context( applicationmanager , inputmanager )
{
}

Context::~Context()
{
}

bool Context::initialize( Json::ValuePtr& config )
{
	return false;
}

graphics::RenderTarget::Ptr Context::getRenderTarget()
{
	graphics::RenderTarget::Ptr tt;
	return tt;
}

} // namespace core 
