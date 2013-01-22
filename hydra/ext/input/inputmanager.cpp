/*
 * inputmanager.cpp
 *
 *  Created on: 22.1.2013
 *      Author: akin
 */

#include "inputmanager.hpp"

namespace input {


std::vector<Source::WeakPtr> Manager::sources;

void Manager::attach( Source::Ptr ptr )
{
	// the source must be unique
	for( auto& source : sources )
	{
		// weak -> shared
		if( auto real = source.lock() )
		{
			if( ptr == real )
			{
				return;
			}
		}
	}
	// shared -> weak
	sources.push_back( ptr );
}

void Manager::get( const String8& name , Source::Ptr ptr )
{
	for( auto& source : sources )
	{
		// weak -> shared
		if( auto real = source.lock() )
		{
			if( real->getName() == name )
			{
				ptr = real;
			}
		}
	}
}

void Manager::get( Mode mode , Source::Ptr ptr )
{
	for( auto& source : sources )
	{
		// weak -> shared
		if( auto real = source.lock() )
		{
			if( real->getMode() == mode )
			{
				ptr = real;
			}
		}
	}
}

void Manager::get( Type type , Source::Ptr ptr )
{
	for( auto& source : sources )
	{
		// weak -> shared
		if( auto real = source.lock() )
		{
			if( real->getType() == type )
			{
				ptr = real;
			}
		}
	}
}

void Manager::clean()
{
	auto iter = sources.begin();
	while( iter != sources.end() )
	{
		if( auto real = iter->lock() )
		{
			continue;
		}
		// could not lock.. must be dead.
		iter = sources.erase( iter );
	}
}

} // namespace input 
