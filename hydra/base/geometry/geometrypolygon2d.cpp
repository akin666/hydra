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

bool Polygon2D::hitTest( const glm::vec2& point ) const
{
	// game coding complete 4th edition page 300.
	bool inside = false;
	size_t size = vertexes.size();

	if( size < 3 )
	{
		return false;
	}

	for( uint32 i = 0 ; i < size ; ++i )
	{
		glm::vec2& curr = vertexes[ i ];
		glm::vec2& prev = vertexes[ (size - 1 + i) % size  ];

		if( curr.x > prev.x )
		{
			if( (curr.x < point.x) == (point.x <= prev.x) &&
				(point.y - prev.y) * (curr.x-prev.x) < (curr.y-prev.y) * (point.x-prev.x) )
			{
				inside = !inside;
			}
			continue;
		}
		if( (curr.x < point.x) == (point.x <= prev.x) &&
			(point.y - curr.y) * (prev.x-curr.x) < (prev.y-curr.y) * (point.x-curr.x) )
		{
			inside = !inside;
		}
	}

	return inside;
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
