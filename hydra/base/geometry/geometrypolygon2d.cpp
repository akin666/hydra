/*
 * geometrypolygon2d.cpp
 *
 *  Created on: 7.2.2013
 *      Author: akin
 */

#include "geometrypolygon2d.hpp"

namespace geometry {

Polygon2D::Polygon2D()
{
}

Polygon2D::~Polygon2D()
{
}

void Polygon2D::clear()
{
	vertexes.clear();
	indices.clear();
}

bool Polygon2D::tesselate()
{
	return false;
}

bool Polygon2D::hitTest( const glm::vec2& point )
{
	return false;
}

Vertex2DSet& Polygon2D::getVertexes()
{
	return vertexes;
}

IndexSet& Polygon2D::getIndexes()
{
	return indices;
}

} // namespace geometry
