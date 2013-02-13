/*
 * geometrypolygon2d.hpp
 *
 *  Created on: 7.2.2013
 *      Author: akin
 */

#ifndef GEOMETRYPOLYGON2D_HPP_
#define GEOMETRYPOLYGON2D_HPP_

#include "geometry2d.hpp"

namespace geometry {

class Polygon2D : public HitTestInterface
{
private:
	Vertex2DSet vertexes;
	IndexSet indices;
public:
	Polygon2D();
	virtual ~Polygon2D();

	void clear();

	bool tesselate();

	virtual bool hitTest( const glm::vec2& point ) const;

	Vertex2DSet& getVertexes();
	IndexSet& getIndexes();
};

} // namespace geometry
#endif // GEOMETRYPOLYGON2D_HPP_
