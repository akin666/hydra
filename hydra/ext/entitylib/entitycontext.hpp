/*
 * entitycontext.hpp
 *
 *  Created on: 4.12.2012
 *      Author: akin
 */

#ifndef ENTITYCONTEXT_HPP_
#define ENTITYCONTEXT_HPP_

#include "entity.hpp"
#include "entityproperty.hpp"
#include "entitymanager.hpp"
#include <unordered_map>
#include <memory>	// c++11 std::shared_ptr

namespace entity {

class Context
{
public:
	typedef std::shared_ptr<Context> Ptr;
	typedef std::weak_ptr<Context> WeakPtr;
private:
	std::atomic<ID> current;

	Manager manager;
	PropertyMap properties;
public:
	Context();
	~Context();

	ID create();
	void destroy( ID id );

	// Property access methods.
	template < class PropertyType >
	void add()
	{
		get<PropertyType>();
	}

	template < class PropertyType >
	void remove()
	{
		auto iter = properties.find( PropertyType::type );
		if( properties.end() != iter )
		{
			delete *iter;
			properties.erase( iter );
		}
	}

	template < class PropertyType >
	PropertyType& get()
	{
		auto iter = properties.find( PropertyType::type );
		if( properties.end() != iter )
		{
			return *(dynamic_cast<PropertyType*>(iter->second));
		}

		PropertyType *tmp = new PropertyType( manager );
		properties[PropertyType::type] = tmp;
		return *tmp;
	}
};

} // namespace entity
#endif // ENTITYCONTEXT_HPP_
