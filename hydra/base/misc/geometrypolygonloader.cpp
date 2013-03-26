/*
 * geometrypolygonloader.cpp
 *
 *  Created on: 7.2.2013
 *      Author: akin
 */

#include "geometrypolygonloader.hpp"

namespace geometry {

PolygonLoader::PolygonLoader()
{
}

PolygonLoader::~PolygonLoader()
{
}

bool PolygonLoader::canLoad( const std::string& path )
{
	return false;
}

bool PolygonLoader::load( const std::string& path , Polygon& target )
{
	return false;
}

} // namespace geometry
