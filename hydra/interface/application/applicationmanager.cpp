/*
 * applicationmanager.cpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#include "applicationmanager.hpp"

namespace application {

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

void Manager::get( Source::Ptr& ptr )
{
}

void Manager::clean()
{
}

} // namespace application 
