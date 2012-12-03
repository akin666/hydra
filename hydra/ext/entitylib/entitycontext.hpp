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
#include <unordered_map>

namespace entity {

class Context
{
private:
	typedef std::unordered_map< ID , PropertySet > PropertyMap;

	std::atomic<ID> current;
	PropertySet properties;

	PropertyMap data;
public:
	Context();
	~Context();

	ID create();
	void destroy( ID id );

	void attach( ID id , Property *property );
	void detach( ID id , Property *property );
};

} // namespace entity
#endif // ENTITYCONTEXT_HPP_
