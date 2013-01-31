/*
 * glfwrendertarget.cpp
 *
 *  Created on: 30.1.2013
 *      Author: akin
 */

#include "glfwrendertarget.hpp"
#include <stdgl>

namespace glfw {

#define GLFW_RENDERTARGET_NONE 		0x0000
#define GLFW_RENDERTARGET_CLIPPING 	0x0001

#define SCREEN "core.screen"

RenderTarget::RenderTarget()
: state( GLFW_RENDERTARGET_NONE )
{
}

RenderTarget::~RenderTarget()
{
}

// Current modes
pixel::Format RenderTarget::getColorMode() const
{
	return settings.getColorMode();
}

pixel::Format RenderTarget::getDepthMode() const
{
	return settings.getDepthMode();
}

glm::ivec2 RenderTarget::getDimensions() const
{
	return settings.getDimensions();
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
	Json::Value *value = Json::Helper::getValue( *config.get() , SCREEN );

	if( value != nullptr )
	{
		settings.parse( value );
	}
	else
	{
		settings.setWidth( 800 );
		settings.setWidth( 600 );

		settings.setRed( 8 );
		settings.setGreen( 8 );
		settings.setBlue( 8 );
		settings.setAlpha( 8 );

		settings.setDepth( 32 );
		settings.setStencil( 0 );

		settings.setFullscreen( false );
	}

	if( glfwOpenWindow(
			settings.getDimensions().x,
			settings.getDimensions().y,
			settings.getRed(),
			settings.getGreen(),
			settings.getBlue(),
			settings.getAlpha(),
			settings.getDepth(),
			settings.getStencil(),
			settings.getFullscreen() ? GLFW_FULLSCREEN : GLFW_WINDOW
			) == GL_FALSE )
	{
		// Failed!
		return false;
	}

	if( value != nullptr )
	{
		glfwSetWindowTitle( Json::Helper::get( value , "title" ,  String8("HYDRAx0") ).c_str() );
	}
	else
	{
		glfwSetWindowTitle( "HYDRAx0" );
	}


	return true;
}

} // namespace glfw 
