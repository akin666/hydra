/*
 * graphicssettings.cpp
 *
 *  Created on: 12.7.2012
 *      Author: akin
 */

#include "graphicssettings.hpp"

namespace graphics {

#define VIDMODEF_NONE                   0x0000
#define VIDMODEF_FULLSCREEN             0x0001

Settings::Settings()
: dpi(0)
, stencil(0)
, depth(0)
, flags(VIDMODEF_NONE)
{
}

Settings::Settings( const Settings& other )
: dpi(other.dpi)
, colors(other.colors)
, stencil(other.stencil)
, depth(other.depth)
, flags(other.flags)
{
}

Settings::~Settings()
{
}

void Settings::Settings::parse( Json::Value *value )
{
	setWidth( Json::Helper::get( value , "width" ,  640 ) );
	setHeight( Json::Helper::get( value , "height" ,  480 ) );

	setDpi( Json::Helper::get( value , "dpi" ,  72 ) );

	setRed( Json::Helper::get( value , "red" ,  8 ) );
	setGreen( Json::Helper::get( value , "green" ,  8 ) );
	setBlue( Json::Helper::get( value , "blue" ,  8 ) );
	setAlpha( Json::Helper::get( value , "alpha" ,  8 ) );
	setStencil( Json::Helper::get( value , "stencil" ,  8 ) );
	setDepth( Json::Helper::get( value , "depth" ,  24 ) );
	setFullscreen( Json::Helper::get( value , "fullscreen" , false ) );
}

int32 Settings::getAlpha() const
{
	return colors.a;
}

void Settings::setAlpha(int32 alpha)
{
	colors.a = alpha;
}

int32 Settings::getBlue() const
{
	return colors.b;
}

void Settings::setBlue(int32 blue)
{
	colors.b = blue;
}

int32 Settings::getDepth() const
{
	return depth;
}

void Settings::setDepth(int32 depth)
{
	this->depth = depth;
}

const glm::ivec2& Settings::getDimensions() const
{
	return dimensions;
}

void Settings::setDimensions(const glm::ivec2& dimensions)
{
	this->dimensions = dimensions;
}

void Settings::setWidth( int width )
{
	this->dimensions.x = width;
}

void Settings::setHeight( int height )
{
	this->dimensions.y = height;
}

float32 Settings::getDpi() const
{
	return dpi;
}

void Settings::setDpi(float32 dpi)
{
	this->dpi = dpi;
}

int32 Settings::getGreen() const
{
	return colors.g;
}

void Settings::setGreen(int32 green)
{
	colors.g = green;
}

int32 Settings::getRed() const
{
	return colors.r;
}

void Settings::setRed(int32 red)
{
	colors.r = red;
}

int32 Settings::getStencil() const
{
	return stencil;
}

void Settings::setStencil(int32 stencil)
{
	this->stencil = stencil;
}

bool Settings::getFullscreen() const
{
	return (flags&VIDMODEF_FULLSCREEN) != 0;
}

void Settings::setFullscreen(bool val)
{
	if( val )
	{
		flags |= VIDMODEF_FULLSCREEN;
	}
	else
	{
		flags &= ~VIDMODEF_FULLSCREEN;
	}
}

pixel::Format Settings::getColorMode() const
{
	return pixel::resolveColorFormat( colors );
}

pixel::Format Settings::getDepthMode() const
{
	return pixel::resolveDepthFormat( depth );
}

} // namespace graphics 
