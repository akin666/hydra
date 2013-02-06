/*
 * geometrypolygon.cpp
 *
 *  Created on: 6.2.2013
 *      Author: akin
 */

#include "geometrypolygon.hpp"

namespace geometry {

Polygon::Polygon()
{
}

Polygon::~Polygon()
{
}

void Polygon::clear()
{
	vertexes.clear();
	indices.clear();
}

VertexSet& Polygon::getVertexes()
{
	return vertexes;
}

IndexSet& Polygon::getIndexes()
{
	return indices;
}

} // namespace geometry
