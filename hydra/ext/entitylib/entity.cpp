/*
 * entity.cpp
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#include "entity.hpp"
#include "propertymanager.hpp"

#define FIRST_ENTITY 32

namespace entity {

const ID Id::null = 0;
std::atomic<ID> Id::current( FIRST_ENTITY );

ID Id::create()
{
	return ++current;
}

void Id::destroy( ID id )
{
	if( id == null )
	{
		return;
	}
	// Destroy ID
	// (or at least, all its datasets)
	PropertyManager::detachAll( id );
}

Id::Id()
{
}

} // entity

