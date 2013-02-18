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

	virtual bool hitTest( const glm::vec2& point ) const;

	Vertex2DSet& getVertexes();
	IndexSet& getIndexes();

	void tesselate();

	void createBox( glm::vec2 mid , float width , float height );
	void createEllipse( glm::vec2 mid , float width , float height , float count );
	void createCircle( glm::vec2 mid , float radius , float count );
	void createTriangle( glm::vec2 v1 , glm::vec2 v2 , glm::vec2 v3 );
	void createLine( glm::vec2 start , glm::vec2 end , float width );
};

} // namespace geometry
#endif // GEOMETRYPOLYGON2D_HPP_
