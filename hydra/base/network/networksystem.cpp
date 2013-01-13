/*
 * networksystem.cpp
 *
 *  Created on: 12.1.2013
 *      Author: akin
 */

#include "networksystem.hpp"

namespace network {

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
	return true;
}

} // namespace network
