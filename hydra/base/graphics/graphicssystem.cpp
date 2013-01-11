/*
 * graphicssystem.cpp
 *
 *  Created on: 12.1.2013
 *      Author: akin
 */

#include "graphicssystem.hpp"

namespace graphics {

System::System()
{
}

System::~System()
{
}

void System::uninitialize()
{
}

bool System::initialize( cfg::Config& config )
{
	return true;
}

} // namespace graphics
