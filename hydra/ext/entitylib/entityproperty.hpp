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

class Property
{
protected:
	virtual void attachEntity( ID id );
	virtual void detachEntity( ID id );
	virtual void enableEntity( bool enabled , ID id );
public:
	Property();
	virtual ~Property();

	void attach( ID id );
	void detach( ID id );
	void enable( bool enabled , ID id );

	virtual bool has( ID id );

	virtual string8 getName();
};

typedef std::vector< Property* > PropertySet;

} // namespace entity
#endif // ENTITYLIB_PROPERTY_HPP_
