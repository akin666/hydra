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
: dpi( 96 )
, stencil( 0 )
, depth( 0 )
, fullscreen( false )
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
	dimensions.x = Json::Helper::get( config , GRAPHICS ".width" ,  640 );
	dimensions.y = Json::Helper::get( config , GRAPHICS ".height" ,  480 );

	dpi = Json::Helper::get( config , GRAPHICS ".dpi" ,  72 );

	colors.r = Json::Helper::get( config , GRAPHICS ".red" ,  8 );
	colors.g = Json::Helper::get( config , GRAPHICS ".green" ,  8 );
	colors.b = Json::Helper::get( config , GRAPHICS ".blue" ,  8 );
	colors.a = Json::Helper::get( config , GRAPHICS ".alpha" ,  8 );

	stencil = Json::Helper::get( config , GRAPHICS ".stencil" ,  8 );
	depth = Json::Helper::get( config , GRAPHICS ".depth" ,  24 );

	print();

	return true;
}

void System::print() const
{
	LOG->message( "%s:%i " , __FILE__ , __LINE__ );
	LOG->message( " Dimensions: %ix%i DPI: %i R:%i G:%i B:%i A:%i Stencil:%i Depth:%i" ,
			dimensions.x ,
			dimensions.y ,
			dpi ,
			colors.r ,
			colors.g ,
			colors.b ,
			colors.a ,
			stencil ,
			depth );
}

} // namespace graphics
