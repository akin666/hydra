/*
 * graphicssystem.cpp
 *
 *  Created on: 12.1.2013
 *      Author: akin
 */

#include "graphicssystem.hpp"

#define GRAPHICS "graphics"

namespace graphics {

System::System()
{
}

System::~System()
{
	uninitialize();
}

void System::uninitialize()
{
}

bool System::initialize( Json::ValuePtr& config )
{
	Json::Value *value = Json::Helper::getValue( *config.get() , GRAPHICS );

	if( value != nullptr )
	{
		settings.parse( value );
	}
	else
	{
		settings.setWidth( Json::Helper::get( config , GRAPHICS ".width" ,  640 ) );
		settings.setHeight( Json::Helper::get( config , GRAPHICS ".height" ,  480 ) );

		settings.setDpi( Json::Helper::get( config , GRAPHICS ".dpi" ,  72 ) );

		settings.setRed( Json::Helper::get( config , GRAPHICS ".red" ,  8 ) );
		settings.setGreen( Json::Helper::get( config , GRAPHICS ".green" ,  8 ) );
		settings.setBlue( Json::Helper::get( config , GRAPHICS ".blue" ,  8 ) );
		settings.setAlpha( Json::Helper::get( config , GRAPHICS ".alpha" ,  8 ) );
		settings.setStencil( Json::Helper::get( config , GRAPHICS ".stencil" ,  8 ) );
		settings.setDepth( Json::Helper::get( config , GRAPHICS ".depth" ,  24 ) );
	}

	return true;
}

void System::print() const
{
}

} // namespace graphics
