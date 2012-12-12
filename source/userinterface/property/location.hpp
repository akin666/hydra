/*
 * location.hpp
 *
 *  Created on: 12.12.2012
 *      Author: akin
 */

#ifndef LOCATION_HPP_
#define LOCATION_HPP_

#include <stdtypes>
#include <glm/glm>
#include <entitylib/tproperty.hpp>

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

#endif /* LOCATION_HPP_ */
