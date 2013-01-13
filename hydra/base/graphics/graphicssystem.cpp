/*
 * graphicssystem.cpp
 *
 *  Created on: 12.1.2013
 *      Author: akin
 */

#include "graphicssystem.hpp"
#include <log>

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
	if( Json::Helper::has( config , "graphics.width" ) )
	{
		LOG->message("Hai have width");
	}

	return true;
}

} // namespace graphics
