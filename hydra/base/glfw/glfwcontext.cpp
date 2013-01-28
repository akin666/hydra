/*
 * glfwcontext.cpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#include "glfwcontext.hpp"

namespace glfw {

Context::Context()
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
