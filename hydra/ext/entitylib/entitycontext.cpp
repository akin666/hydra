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
: current(FIRST_ENTITY)
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
	// (or at least, all its datasets)
//	PropertyManager::detachAll( id );
}

void Context::attach( ID id , Property *property )
{
}

void Context::detach( ID id , Property *property )
{
}

} // namespace entity
