/*
 * inputmanager.cpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#include "inputmanager.hpp"

namespace input {

Manager::Manager()
{
}

Manager::~Manager()
{
}

void Manager::attach( Source::Ptr& ptr )
{
	for( auto& weak : set )
	{
		// weak -> shared
		if( auto real = weak.lock() )
		{
			if( ptr == real )
			{
				return;
			}
		}
	}

	// shared -> weak
	set.push_back( ptr );
}

void Manager::get( const String8& name , Source::Ptr& ptr )
{
}

void Manager::get( Mode mode , Source::Ptr& ptr )
{
}

void Manager::get( Type type , Source::Ptr& ptr )
{
}

void Manager::clean()
{
}

void Manager::get( Mode& mode ) const
{
}

void Manager::get( Type& mode ) const
{
}

void Manager::get( StringSet& names ) const
{
}

} // namespace input 
