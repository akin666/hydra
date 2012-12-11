/*
 * usernterfacefactory.cpp
 *
 *  Created on: 11.12.2012
 *      Author: akin
 */

#include "userinterfacefactory.hpp"

#include "property/graphicsproperty.hpp"
#include "property/locationproperty.hpp"
#include "property/textproperty.hpp"

UserInterfaceFactory::UserInterfaceFactory( entity::Context& context )
: graphics( context.get<GraphicsProperty>() )
, location( context.get<LocationProperty>() )
, text( context.get<TextProperty>() )
{
}

UserInterfaceFactory::~UserInterfaceFactory()
{
}

