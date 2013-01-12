/*
 * audiosystem.cpp
 *
 *  Created on: 12.1.2013
 *      Author: akin
 */

#include "audiosystem.hpp"

namespace audio {

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

bool System::initialize( cfg::Config& config )
{
	return true;
}

} // namespace audio
