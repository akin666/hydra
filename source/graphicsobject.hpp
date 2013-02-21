/*
 * graphicsobject.hpp
 *
 *  Created on: 21.2.2013
 *      Author: akin
 */

#ifndef GRAPHICSOBJECT_HPP_
#define GRAPHICSOBJECT_HPP_

#include <geometry/geometrypolygon2d.hpp>

class GraphicsObject
{
public:
	GraphicsObject();
	~GraphicsObject();

	geometry::Polygon2D poly;
	glm::vec4 color;
	glm::mat4 position;
};

#endif // GRAPHICSOBJECT_HPP_
