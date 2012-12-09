/*
 * tproperty.hpp
 *
 *  Created on: 16.6.2012
 *      Author: akin
 */

#ifndef ENTITYLIB_TPROPERTY_HPP_
#define ENTITYLIB_TPROPERTY_HPP_

#include "entityproperty.hpp"
#include <unordered_map>
#include <allocation/allocationpool>

namespace entity {

template <class PType>
class TProperty : public Property
{
protected:
	typedef std::unordered_map< ID , PType* > Map;

	Map data;
	allocation::Pool<PType> pool;

	virtual void attachEntity( EntityID id )
	{
		get( id );
	}

	virtual void detachEntity( EntityID id )
	{
		typename Map::iterator iter = data.find( id );
		if( iter == data.end() )
		{
			return;
		}

		PType *n = iter->second;
		data.erase( iter );
		pool.destruct( n );
		pool.sort();
	}
public:
	TProperty()
	{
	}

	virtual bool has( EntityID id )
	{
		return data.find( id ) != data.end();
	}

	virtual void clear()
	{
		pool.clear();
	}

	PType& get( EntityID id )
	{
		typename Map::iterator iter = data.find( id );
		if( iter != data.end() )
		{
			return *(iter->second);
		}

		PType *n = pool.construct();
		data[ id ] = n;
		return *n;
	}

	PType *getNoCreate( EntityID id )
	{
		typename Map::iterator iter = data.find( id );
		if( iter != data.end() )
		{
			return (iter->second);
		}

		return nullptr;
	}
};

} // namespace orion
#endif // ENTITYLIB_TPROPERTY_HPP_
