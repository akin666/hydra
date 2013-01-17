/*
 * resourcehandle.cpp
 *
 *  Created on: 18.1.2013
 *      Author: akin
 */

#include "resourcehandle.hpp"
#include "resourcecache.hpp"

namespace resource {

Handle::Handle( const String8& name , Cache *parent )
: parent( parent )
, name( name )
{
}

Handle::~Handle()
{
}

const String8& Handle::getName() const
{
	return name;
}

void Handle::setName( const String8& name )
{
	this->name = name;
}

bool Handle::isLoaded() const
{
	return false;
}

void Handle::load()
{
}

void Handle::unload()
{
}

void Handle::getNullObject( Ptr& nullObjectPtr )
{
}

} // namespace resource
