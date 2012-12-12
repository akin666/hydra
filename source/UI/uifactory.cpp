/*
 * usernterfacefactory.cpp
 *
 *  Created on: 11.12.2012
 *      Author: akin
 */

#include "uifactory.hpp"

namespace ui {

Factory::Factory( entity::Context& context )
: graphics( context.get<GraphicsProperty>() )
, location( context.get<LocationProperty>() )
, text( context.get<TextProperty>() )
{
}

Factory::~Factory()
{
}

} // namespace ui
