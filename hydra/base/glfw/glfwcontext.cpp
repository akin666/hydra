/*
 * glfwcontext.cpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#include "glfwcontext.hpp"
#include "glfwrendertarget.hpp"

namespace glfw {

Context::Context()
{
}

Context::~Context()
{
}

bool Context::initialize( Json::ValuePtr& config )
{
	// Load rendertarget
	{
		RenderTarget *rtarget = new RenderTarget;
		rendertarget = graphics::RenderTarget::Ptr( rtarget );
	}

	return false;
}

void Context::getRenderTarget( graphics::RenderTarget::Ptr& ptr )
{
}

} // namespace core 
