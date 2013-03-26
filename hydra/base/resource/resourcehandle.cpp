/*
 * resourcehandle.cpp
 *
 *  Created on: 18.1.2013
 *      Author: akin
 */

#include "resourcehandle.hpp"
#include "resourcecache.hpp"

namespace resource {

Handle::Handle( const std::string& name , Cache *parent )
: parent( parent )
, name( name )
{
}

Handle::~Handle()
{
}

const std::string& Handle::getName() const
{
	return name;
}

void Handle::setName( const std::string& name )
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
