/*
 * geometrypolygon.hpp
 *
 *  Created on: 6.2.2013
 *      Author: akin
 */

#ifndef GEOMETRYPOLYGON_HPP_
#define GEOMETRYPOLYGON_HPP_

#include <commontypes.h>

namespace geometry {

class Polygon
{
private:
	VertexSet vertexes;
	IndexSet indices;
public:
	Polygon();
	~Polygon();

	void clear();

	VertexSet& getVertexes();
	IndexSet& getIndexes();
};

} // namespace geometry
#endif // GEOMETRYPOLYGON_HPP_
