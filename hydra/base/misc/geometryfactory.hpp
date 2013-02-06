/*
 * geometryfactory.hpp
 *
 *  Created on: 7.2.2013
 *      Author: akin
 */

#ifndef GEOMETRYFACTORY_HPP_
#define GEOMETRYFACTORY_HPP_

#include "geometrypolygonloader.hpp"

namespace geometry {

class Factory
{
private:
	std::vector<PolygonLoader*> loaders;
public:
	Factory();
	~Factory();

	template <class PLoadClass> void attach()
	{
		loaders.push_back( new PLoadClass );
	}

	bool load( const String8& path , Polygon& polygon );
};

} // namespace geometry
#endif // GEOMETRYFACTORY_HPP_
