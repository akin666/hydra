/*
 * geometryfactory.cpp
 *
 *  Created on: 7.2.2013
 *      Author: akin
 */

#include "geometryfactory.hpp"

namespace geometry {

Factory::Factory()
{
}

Factory::~Factory()
{
	for( auto iter = loaders.begin() ; iter != loaders.end() ; ++iter )
	{
		delete *iter;
	}
	loaders.clear();
}

bool Factory::load( const std::string& path , Polygon& polygon )
{
	for( auto& loader : loaders )
	{
		if( loader->canLoad( path ) )
		{
			if( !loader->load( path , polygon ) )
			{
				polygon.clear();
				continue;
			}
			return true;
		}
	}
	return false;
}

} // namespace geometry
