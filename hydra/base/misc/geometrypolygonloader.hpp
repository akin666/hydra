/*
 * geometrypolygonloader.hpp
 *
 *  Created on: 7.2.2013
 *      Author: akin
 */

#ifndef GEOMETRYPOLYGONLOADER_HPP_
#define GEOMETRYPOLYGONLOADER_HPP_

#include <commontypes.h>
#include <geometry/geometrypolygon.hpp>

namespace geometry {

class PolygonLoader
{
public:
	PolygonLoader();
	virtual ~PolygonLoader();

	virtual bool canLoad( const std::string& path );
	virtual bool load( const std::string& path , Polygon& target );
};

} // namespace geometry
#endif // GEOMETRYPOLYGONLOADER_HPP_
