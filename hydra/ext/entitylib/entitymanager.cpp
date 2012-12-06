/*
 * entitymanager.cpp
 *
 *  Created on: 7.12.2012
 *      Author: akin
 */

#include "entitymanager.hpp"

namespace entity {

Manager::Manager()
{
}

Manager::~Manager()
{
}

void Manager::reg( ID id, Property* property )
{
	data[ id ].push_back( property );
}

void Manager::unreg( ID id, Property* property )
{
	auto diter = data.find( id );
	if( diter == data.end() )
	{
		return;
	}

	auto psset = diter->second;
	for( auto iter = psset.begin() ; iter != psset.end() ; ++iter )
	{
		if( *iter == property )
		{
			psset.erase( iter );
			return;
		}
	}
}

void Manager::clear( ID id )
{
	auto diter = data.find( id );
	if( diter == data.end() )
	{
		return;
	}

	for( auto iter : diter->second )
	{
		iter->detachEntity( id );
	}

	data.erase( diter );
}

void Manager::clear()
{
	for( auto diter = data.begin() ; diter != data.end() ; ++diter )
	{
		for( auto iter : diter->second )
		{
			iter->detachEntity( diter->first );
		}
	}
	data.clear();
}

} // namespace entity
