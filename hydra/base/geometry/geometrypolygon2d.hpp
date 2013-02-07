/*
 * geometrypolygon2d.hpp
 *
 *  Created on: 7.2.2013
 *      Author: akin
 */

#ifndef GEOMETRYPOLYGON2D_HPP_
#define GEOMETRYPOLYGON2D_HPP_

#include <commontypes.h>

namespace geometry {

class Polygon2D
{
private:
	Vertex2DSet vertexes;
	IndexSet indices;
public:
	Polygon2D();
	~Polygon2D();

	void clear();

	bool tesselate();

	bool hitTest( const glm::vec2& point );

	Vertex2DSet& getVertexes();
	IndexSet& getIndexes();
};

} // namespace geometry
#endif // GEOMETRYPOLYGON2D_HPP_
