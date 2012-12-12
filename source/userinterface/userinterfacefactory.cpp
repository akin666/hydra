/*
 * usernterfacefactory.cpp
 *
 *  Created on: 11.12.2012
 *      Author: akin
 */

#include "userinterfacefactory.hpp"

UserInterfaceFactory::UserInterfaceFactory( entity::Context& context )
: graphics( context.get<GraphicsProperty>() )
, location( context.get<LocationProperty>() )
, text( context.get<TextProperty>() )
{
}

UserInterfaceFactory::~UserInterfaceFactory()
{
}

