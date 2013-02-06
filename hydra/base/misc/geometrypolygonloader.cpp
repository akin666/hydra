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

bool PolygonLoader::canLoad( const String8& path )
{
	return false;
}

bool PolygonLoader::load( const String8& path , Polygon& target )
{
	return false;
}

} // namespace geometry
