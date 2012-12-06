/*
 * entity.hpp
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#ifndef ENTITYLIB_ENTITY_HPP_
#define ENTITYLIB_ENTITY_HPP_

#include <stdtypes>
#include <unordered_map>

namespace entity {

typedef uint64 ID;

extern const ID null;

typedef std::unordered_map<ID , ID> IDMap;
typedef std::vector<ID> IDSet;

/*
class Data
{
public:
	ducktype void dtor() = 0;
	ducktype void ctor() = 0;
};
*/

} // entity

#endif // ENTITYLIB_ENTITY_HPP_
