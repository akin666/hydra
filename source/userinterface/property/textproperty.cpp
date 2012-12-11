/*
 * textproperty.cpp
 *
 *  Created on: 12.12.2012
 *      Author: akin
 */

#include "textproperty.hpp"

using namespace entity;

ducktype string8 TextProperty::type("text");

// Inherited attach & detach methods
void TextProperty::attachEntity( ID id )
{
	get( id );
}

void TextProperty::detachEntity( ID id )
{
	typename Map::iterator iter = data.find( id );
	if( iter == data.end() )
	{
		return;
	}

	Text *n = iter->second;
	data.erase( iter );
	pool.destruct( n );
	pool.sort();
}

// Member functions
TextProperty::TextProperty( Manager& manager )
: Property( manager )
{
}

TextProperty::~TextProperty( )
{
}

bool TextProperty::has( ID id )
{
	return data.find( id ) != data.end();
}

void TextProperty::clear()
{
	pool.clear();
}

Text& TextProperty::get( ID id )
{
	typename Map::iterator iter = data.find( id );
	if( iter != data.end() )
	{
		return *(iter->second);
	}

	Text *n = pool.construct();
	data[ id ] = n;
	return *n;
}

Text *TextProperty::getNoCreate( ID id )
{
	typename Map::iterator iter = data.find( id );
	if( iter != data.end() )
	{
		return (iter->second);
	}

	return nullptr;
}

