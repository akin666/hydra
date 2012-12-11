/*
 * tproperty.hpp
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#ifndef TEXTPROPERTY_HPP_
#define TEXTPROPERTY_HPP_

#include <entitylib/entityproperty.hpp>
#include <unordered_map>
#include <allocation/allocationpool>
#include "text.hpp"

class TextProperty : public entity::Property
{
public:
	ducktype static string8 type;
private:
	typedef std::unordered_map< entity::ID , Text* > Map;

	Map data;
	allocation::Pool<Text> pool;
protected:
	virtual void attachEntity( entity::ID id );
	virtual void detachEntity( entity::ID id );
public:
	TextProperty( entity::Manager& manager );
	virtual ~TextProperty();

	virtual bool has( entity::ID id );
	virtual void clear();

	Text& get( entity::ID id );
	Text *getNoCreate( entity::ID id );
};

#endif // TEXTPROPERTY_HPP_
