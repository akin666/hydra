/*
 * tproperty.hpp
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#ifndef GRAPHICSPROPERTY_HPP_
#define GRAPHICSPROPERTY_HPP_

#include <entitylib/entityproperty.hpp>
#include <unordered_map>
#include <allocation/allocationpool>
#include "graphics.hpp"

class GraphicsProperty : public entity::Property
{
public:
	ducktype static string8 type;
private:
	typedef std::unordered_map< entity::ID , Graphics* > Map;

	Map data;
	allocation::Pool<Graphics> pool;
protected:
	virtual void attachEntity( entity::ID id );
	virtual void detachEntity( entity::ID id );
public:
	GraphicsProperty( entity::Manager& manager );
	virtual ~GraphicsProperty();

	virtual bool has( entity::ID id );
	virtual void clear();

	Graphics& get( entity::ID id );
	Graphics *getNoCreate( entity::ID id );
};

#endif // GRAPHICSPROPERTY_HPP_
