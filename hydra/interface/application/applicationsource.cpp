/*
 * applicationsource.cpp
 *
 *  Created on: 24.1.2013
 *      Author: akin
 */

#include "applicationsource.hpp"

namespace application {

Source::Source()
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

} // namespace application 
