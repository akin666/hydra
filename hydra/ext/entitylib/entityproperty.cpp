/*
 * property.cpp
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#include "entityproperty.hpp"
#include "propertymanager.hpp"

namespace entity {

Property::Property()
{
}

Property::~Property()
{
}

void Property::attachEntity( ID id )
{
}

void Property::detachEntity( ID id )
{
}

void Property::enableEntity( bool enabled , ID id )
{
}

void Property::attach( ID id )
{
	PropertyManager::attach( id , this );
	attachEntity( id );
}

void Property::detach( ID id )
{
	PropertyManager::detach( id , this );
	detachEntity( id );
}

void Property::enable( bool enabled , ID id )
{
	enableEntity( enabled , id );
}

bool Property::has( ID id )
{
	return false;
}

string8 Property::getName()
{
	return "null";
}

} // namespace entity
