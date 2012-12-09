/*
 * entityfactory.cpp
 *
 *  Created on: 9.12.2012
 *      Author: akin
 */

#include "entityfactory.hpp"
#include "entitycontext.hpp"

namespace entity {

Factory::Factory( Context& context )
: context( context )
{
}

Factory::~Factory()
{
}

} // namespace entity
