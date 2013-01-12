/*
 * location.hpp
 *
 *  Created on: 12.12.2012
 *      Author: akin
 */

#ifndef UITEXT_HPP_
#define UITEXT_HPP_

#include <stdtypes>
#include <glm/glm>
#include <entitylib/tproperty.hpp>

namespace ui {

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

	String8 text;
};

typedef entity::TProperty<Text> TextProperty;

} // namespace ui

#endif /* TEXT_HPP_ */
