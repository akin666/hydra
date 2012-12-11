/*
 * locationproperty.cpp
 *
 *  Created on: 12.12.2012
 *      Author: akin
 */

#include "locationproperty.hpp"

using namespace entity;

ducktype string8 LocationProperty::type("location");

// Inherited attach & detach methods
void LocationProperty::attachEntity( ID id )
{
	get( id );
}

void LocationProperty::detachEntity( ID id )
{
	typename Map::iterator iter = data.find( id );
	if( iter == data.end() )
	{
		return;
	}

	Location *n = iter->second;
	data.erase( iter );
	pool.destruct( n );
	pool.sort();
}

// Member functions
LocationProperty::LocationProperty( Manager& manager )
: Property( manager )
{
}

LocationProperty::~LocationProperty( )
{
}

bool LocationProperty::has( ID id )
{
	return data.find( id ) != data.end();
}

void LocationProperty::clear()
{
	pool.clear();
}

Location& LocationProperty::get( ID id )
{
	typename Map::iterator iter = data.find( id );
	if( iter != data.end() )
	{
		return *(iter->second);
	}

	Location *n = pool.construct();
	data[ id ] = n;
	return *n;
}

Location *LocationProperty::getNoCreate( ID id )
{
	typename Map::iterator iter = data.find( id );
	if( iter != data.end() )
	{
		return (iter->second);
	}

	return nullptr;
}

