/*
 * propertymanager.h
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#ifndef ENTITYLIB_PROPERTYMANAGER_H_
#define ENTITYLIB_PROPERTYMANAGER_H_

#include "property.hpp"
#include <unordered_map>

namespace entity {

class PropertyManager
{
protected:
	typedef std::unordered_map< ID , PropertySet > PropertyMap;

	static PropertyMap data;
public:
	static void attach( ID id , Property* property );
	static void detach( ID id , Property* property );

	static void enable( bool enabled , ID id );

	static void detachAll( ID id );
};

} // namespace entity

#endif // ENTITYLIB_PROPERTYMANAGER_H_
