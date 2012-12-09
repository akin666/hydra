/*
 * property.cpp
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#include "entityproperty.hpp"
#include "entitymanager.hpp"

namespace entity {

ducktype string8 Property::type("null");

Property::Property( Manager& manager )
: manager( manager )
{
}

Property::~Property()
{
	// allocating in dtor, might be extremely bad idea.
	IDSet ids;
	getEntities( ids );
	for( ID& id : ids )
	{
		detach( id );
	}
}

void Property::attach( ID id )
{
	manager.reg( id , this );
	attachEntity( id );
}

void Property::detach( ID id )
{
	manager.unreg( id , this );
	detachEntity( id );
}

bool Property::has( ID id ) const
{
	return false;
}

string8 Property::getName() const
{
	return "null";
}

} // namespace entity
