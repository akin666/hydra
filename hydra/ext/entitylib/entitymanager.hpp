/*
 * entitymanager.hpp
 *
 *  Created on: 7.12.2012
 *      Author: akin
 */

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include "entity.hpp"
#include "entityproperty.hpp"

namespace entity {

class Manager
{
private:
	// property should be the only thing registering and unregistering things
	friend class Property;

	typedef std::unordered_map<ID , PropertySet> PropertySetMap;

	PropertySetMap data;

	void reg( ID id , Property *property );
	void unreg( ID id , Property *property );
public:
	Manager();
	~Manager();

	void clear( ID id );
	void clear();
};

} // namespace entity
#endif // ENTITYMANAGER_HPP_
