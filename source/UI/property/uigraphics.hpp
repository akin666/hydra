/*
 * location.hpp
 *
 *  Created on: 12.12.2012
 *      Author: akin
 */

#ifndef UIGRAPHICS_HPP_
#define UIGRAPHICS_HPP_

#include <stdtypes>
#include <glm/glm>
#include <entitylib/tproperty.hpp>

namespace ui {

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

} // namespace ui

#endif /* GRAPHICS_HPP_ */
