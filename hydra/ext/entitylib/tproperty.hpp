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

	virtual void attachEntity( ID id )
	{
		get( id );
	}

	virtual void detachEntity( ID id )
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
	TProperty( Manager& manager )
	: Property( manager )
	{
	}

	virtual bool has( ID id )
	{
		return data.find( id ) != data.end();
	}

	virtual void clear()
	{
		pool.clear();
	}

	PType& get( ID id )
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

	PType *getNoCreate( ID id )
	{
		typename Map::iterator iter = data.find( id );
		if( iter != data.end() )
		{
			return (iter->second);
		}

		return nullptr;
	}
};

} // namespace entity
#endif // ENTITYLIB_TPROPERTY_HPP_
