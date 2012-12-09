/*
 * property.hpp
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#ifndef ENTITYLIB_PROPERTY_HPP_
#define ENTITYLIB_PROPERTY_HPP_

#include "entity.hpp"

namespace entity {

class Manager;
class Property
{
private:
	Manager& manager;
protected:
	// manager needs to call detach attach
	// but i dot want to expose new functions
	// to everyone, so it is a friend.
	friend class Manager;

	// override these functions
	// for attaching/detaching
	virtual void attachEntity( ID id ) = 0;
	virtual void detachEntity( ID id ) = 0;
public:
	ducked static string8 type;

	Property( Manager& manager );
	virtual ~Property();

	void attach( ID id );
	void detach( ID id );

	virtual void clear();
	virtual bool has( ID id ) const;
};

typedef std::vector< Property* > PropertySet;
typedef std::unordered_map< string8 , Property* > PropertyMap;

} // namespace entity
#endif // ENTITYLIB_PROPERTY_HPP_
