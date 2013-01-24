/*
 * inputsource.cpp
 *
 *  Created on: 22.1.2013
 *      Author: akin
 */

#include "inputsource.hpp"

namespace input {

Source::Source( const String8& name , Type type , Mode mode )
: type( type )
, mode( mode )
, name( name )
{
}

Source::~Source()
{
}

void Source::attach( Handler::Ptr ptr )
{
	// the device must be unique
	for( auto& item : items )
	{
		// weak -> shared
		if( auto real = item.lock() )
		{
			if( ptr == real )
			{
				return;
			}
		}
	}
	// shared -> weak
	items.push_back( ptr );
}

String8 Source::getName() const
{
	return name;
}

Type Source::getType() const
{
	return type;
}

Mode Source::getMode() const
{
	return mode;
}

} // namespace input 
