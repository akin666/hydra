/*
 * audioalcontext.cpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#include "openalcontext.hpp"

namespace openal {

Context::Context()
{
}

Context::~Context()
{
}

bool Context::initialize( Json::ValuePtr& config )
{
	return true;
}

} // namespace openal
