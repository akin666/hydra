/*
 * entitycontext.cpp
 *
 *  Created on: 4.12.2012
 *      Author: akin
 */

#include "entitycontext.hpp"

#define FIRST_ENTITY 32

namespace entity {

Context::Context()
: current( FIRST_ENTITY )
, factory( *this )
{
}

Context::~Context()
{
}

ID Context::create()
{
	return ++current;
}

void Context::destroy( ID id )
{
	if( id == null )
	{
		return;
	}
	// Destroy ID
	manager.clear( id );
}

} // namespace entity
