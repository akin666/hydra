/*
 * location.hpp
 *
 *  Created on: 12.12.2012
 *      Author: akin
 */

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <stdtypes>
#include <glm/glm>
#include <entitylib/tproperty.hpp>

class Text
{
public:
	ducktype static const std::string type;

	ducktype void constructor()
	{
	}

	ducktype void destructor()
	{
		text.clear();
	}

	string8 text;
};

typedef entity::TProperty<Text> TextProperty;

#endif /* TEXT_HPP_ */
