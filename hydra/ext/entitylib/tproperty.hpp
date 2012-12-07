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
#include "entitydatapool.hpp"

namespace entity {

template <class PType>
class TProperty : public Property
{
public:
	typedef std::unordered_map< ID , PType* > Map;
protected:
	Map data;
	DataPool<PType> pool;

	virtual void attachEntity( EntityID id )
	{
		typename Map::iterator iter = data.find( id );
		if( iter != data.end() )
		{
			return;
		}

		PType *n = pool.construct();
		data[ id ] = n;
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
	}

	virtual void enableEntity( bool enabled , EntityID id )
	{
		typename Map::iterator iter = data.find( id );
		if( iter == data.end() )
		{
			return;
		}

		PType *n = iter->second;
		n->enable( enabled );
	}
public:
	TProperty()
	{
	}

	virtual ~TProperty()
	{
		// detach all!
	}

	virtual bool has( EntityID id )
	{
		return data.find( id ) != data.end();
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

	// Specialize
	virtual string8 getName()
	{
		return "";
	}
};

} // namespace orion
#endif // ENTITYLIB_TPROPERTY_HPP_
