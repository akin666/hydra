/*
 * glfwrendertarget.cpp
 *
 *  Created on: 30.1.2013
 *      Author: akin
 */

#include "glfwrendertarget.hpp"
#include <stdgl>

namespace glfw {

#define GLFW_RENDERTARGET_NONE 0x0000
#define GLFW_RENDERTARGET_CLIPPING 0x0001

RenderTarget::RenderTarget()
: state( GLFW_RENDERTARGET_NONE )
, colormode( color::RGBA8 )
, depthmode( color::DEPTH32 )
{
}

RenderTarget::~RenderTarget()
{
}

// Current modes
color::Type RenderTarget::getColorMode() const
{
	return colormode;
}

color::Type RenderTarget::getDepthMode() const
{
	return depthmode;
}

glm::ivec2 RenderTarget::getDimensions() const
{
	return dimensions;
}

// Clipping
void RenderTarget::setClipping( const glm::ivec2& dimensions )
{
	clipping = dimensions;
}

glm::ivec2 RenderTarget::getClipping() const
{
	return clipping;
}

void RenderTarget::enableClipping( bool state )
{
	state ? this->state |= GLFW_RENDERTARGET_CLIPPING : this->state &= ~GLFW_RENDERTARGET_CLIPPING;
}

bool RenderTarget::isClipping() const
{
	return (state & GLFW_RENDERTARGET_CLIPPING) == GLFW_RENDERTARGET_CLIPPING;
}

// Clearing (depth, color, whatever)
void RenderTarget::clear()
{
}

void RenderTarget::bind()
{
}

void RenderTarget::unbind()
{
}

bool RenderTarget::initialize( Json::ValuePtr& config )
{
	dimensions.x = 800;
	dimensions.x = 600;

	int r = 8;
	int g = 8;
	int b = 8;
	int a = 8;
	int d = 32;
	int s = 0;
	bool fs = false;

	if( glfwOpenWindow(
			dimensions.x,
			dimensions.y,
			r,
			g,
			b,
			a,
			d,
			s,
			fs ? GLFW_FULLSCREEN : GLFW_WINDOW
			) == GL_FALSE )
	{
		// Failed!
		return false;
	}

	return true;
}

} // namespace glfw 
