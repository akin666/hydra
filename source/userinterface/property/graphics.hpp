/*
 * location.hpp
 *
 *  Created on: 12.12.2012
 *      Author: akin
 */

#ifndef GRAPHICS_HPP_
#define GRAPHICS_HPP_

#include <stdtypes>
#include <glm/glm>
#include <entitylib/tproperty.hpp>

class Graphics
{
public:
	ducktype static const std::string type;

	ducktype void constructor()
	{
	}

	ducktype void destructor()
	{
	}

	// Vertex buffers and that sort of stuff.. maybe even shader selection?
};

typedef entity::TProperty<Graphics> GraphicsProperty;

#endif /* GRAPHICS_HPP_ */
