/*
 * userinterfacefactory.hpp
 *
 *  Created on: 11.12.2012
 *      Author: akin
 */

#ifndef UIFACTORY_HPP_
#define UIFACTORY_HPP_

#include <entitylib/entitycontext.hpp>

#include "property/uigraphics.hpp"
#include "property/uilocation.hpp"
#include "property/uitext.hpp"

namespace ui {

class Factory
{
private:
	GraphicsProperty& graphics;
	LocationProperty& location;
	TextProperty& text;
public:
	Factory( entity::Context& context );
	~Factory();

	// TODO, Add function, that will parse from json, what properties are attached to entity ID.
};

} // namespace ui

#endif // USERINTERFACEFACTORY_HPP_
