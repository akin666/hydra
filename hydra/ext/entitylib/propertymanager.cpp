/*
 * propertymanager.cpp
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#include "propertymanager.hpp"

namespace entity {

// this basically holds a vector for every entity in the program, and that vector holds a pointer to properties that the entity has.
PropertyManager::PropertyMap PropertyManager::data;

void PropertyManager::attach( ID id , Property* property )
{
	PropertySet& pset = data[ id ];
	pset.push_back( property );
}

void PropertyManager::detach( ID id , Property* property )
{
	auto piter = data.find( id );
	if( piter == data.end() )
	{
		return;
	}
	PropertySet& pset = *piter;
	for( auto iter = pset.begin() ; iter != pset.end() ; ++iter )
	{
		if( *iter == property )
		{
			pset.erase( iter );
			return;
		}
	}
}

void PropertyManager::enable( bool enabled , ID id )
{
}

void PropertyManager::detachAll( ID id )
{
	auto piter = data.find( id );
	if( piter == data.end() )
	{
		return;
	}
	PropertySet& pset = *piter;

	for( auto iter = pset.begin() ; iter != pset.end() ; ++iter )
	{
		(*iter)->detach( id );
	}
	data.erase( piter );
}

} // namespace orion
