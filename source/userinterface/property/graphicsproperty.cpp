/*
 * GraphicsProperty.cpp
 *
 *  Created on: 12.12.2012
 *      Author: akin
 */

#include "GraphicsProperty.hpp"

using namespace entity;

ducktype string8 GraphicsProperty::type("graphics");

// Inherited attach & detach methods
void GraphicsProperty::attachEntity( ID id )
{
	get( id );
}

void GraphicsProperty::detachEntity( ID id )
{
	typename Map::iterator iter = data.find( id );
	if( iter == data.end() )
	{
		return;
	}

	Graphics *n = iter->second;
	data.erase( iter );
	pool.destruct( n );
	pool.sort();
}

// Member functions
GraphicsProperty::GraphicsProperty( Manager& manager )
: Property( manager )
{
}

GraphicsProperty::~GraphicsProperty( )
{
}

bool GraphicsProperty::has( ID id )
{
	return data.find( id ) != data.end();
}

void GraphicsProperty::clear()
{
	pool.clear();
}

Graphics& GraphicsProperty::get( ID id )
{
	typename Map::iterator iter = data.find( id );
	if( iter != data.end() )
	{
		return *(iter->second);
	}

	Graphics *n = pool.construct();
	data[ id ] = n;
	return *n;
}

Graphics *GraphicsProperty::getNoCreate( ID id )
{
	typename Map::iterator iter = data.find( id );
	if( iter != data.end() )
	{
		return (iter->second);
	}

	return nullptr;
}

