/*
 * location.hpp
 *
 *  Created on: 12.12.2012
 *      Author: akin
 */

#ifndef UILOCATION_HPP_
#define UILOCATION_HPP_

#include <stdtypes>
#include <glm/glm>
#include <entitylib/tproperty.hpp>

namespace ui {

class Location
{
public:
	ducktype static const std::string type;

	ducktype void constructor()
	{
	}
	ducktype void destructor()
	{
	}

	glm::mat4x4 matrix;
};

typedef entity::TProperty<Location> LocationProperty;

} // namespace ui

#endif /* LOCATION_HPP_ */
