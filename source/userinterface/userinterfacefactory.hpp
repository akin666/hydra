/*
 * userinterfacefactory.hpp
 *
 *  Created on: 11.12.2012
 *      Author: akin
 */

#ifndef USERINTERFACEFACTORY_HPP_
#define USERINTERFACEFACTORY_HPP_

#include <entitylib/entitycontext.hpp>

class GraphicsProperty;
class LocationProperty;
class TextProperty;
class UserInterfaceFactory
{
private:
	GraphicsProperty& graphics;
	LocationProperty& location;
	TextProperty& text;
public:
	UserInterfaceFactory( entity::Context& context );
	~UserInterfaceFactory();

	// TODO, Add function, that will parse from json, what properties are attached to entity ID.
};

#endif // USERINTERFACEFACTORY_HPP_
