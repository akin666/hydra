/*
 * entity.hpp
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#ifndef ENTITYLIB_ENTITY_HPP_
#define ENTITYLIB_ENTITY_HPP_

#include <stdtypes>

namespace entity {

typedef uint64 ID;

class Id
{
private:
	Id();
protected:
	static std::atomic<ID> current;
public:
	static const ID null;

	static ID create();
	static void destroy( ID id );
};

} // entity

#endif // ENTITYLIB_ENTITY_HPP_
