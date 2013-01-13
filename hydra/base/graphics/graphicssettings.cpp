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
, red(0)
, green(0)
, blue(0)
, alpha(0)
, stencil(0)
, depth(0)
, flags(VIDMODEF_NONE)
{
}

Settings::Settings( const Settings& other )
: dpi(other.dpi)
, red(other.red)
, green(other.green)
, blue(other.blue)
, alpha(other.alpha)
, stencil(other.stencil)
, depth(other.depth)
, flags(other.flags)
{
}

Settings::~Settings()
{
}

int32 Settings::getAlpha() const
{
	return alpha;
}

void Settings::setAlpha(int32 alpha)
{
	this->alpha = alpha;
}

int32 Settings::getBlue() const
{
	return blue;
}

void Settings::setBlue(int32 blue)
{
	this->blue = blue;
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
	return green;
}

void Settings::setGreen(int32 green)
{
	this->green = green;
}

int32 Settings::getRed() const
{
	return red;
}

void Settings::setRed(int32 red)
{
	this->red = red;
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

} // namespace graphics 
