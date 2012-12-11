/*
 * tproperty.hpp
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#ifndef LOCATIONPROPERTY_HPP_
#define LOCATIONPROPERTY_HPP_

#include <entitylib/entityproperty.hpp>
#include <unordered_map>
#include <allocation/allocationpool>
#include "location.hpp"

class LocationProperty : public entity::Property
{
public:
	ducktype static string8 type;
private:
	typedef std::unordered_map< entity::ID , Location* > Map;

	Map data;
	allocation::Pool<Location> pool;
protected:
	virtual void attachEntity( entity::ID id );
	virtual void detachEntity( entity::ID id );
public:
	LocationProperty( entity::Manager& manager );
	virtual ~LocationProperty();

	virtual bool has( entity::ID id );
	virtual void clear();

	Location& get( entity::ID id );
	Location *getNoCreate( entity::ID id );
};

#endif // LOACTIONSPROPERTY_HPP_
