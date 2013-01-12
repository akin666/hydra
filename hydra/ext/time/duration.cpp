/*
 * duration.cpp
 *
 *  Created on: 26.7.2012
 *      Author: akin
 */

#include "duration.hpp"

namespace time {

Duration::Duration()
: begin( 0 ),
  length( 0 )
{
}

void Duration::setName( const String8& name )
{
	this->name = name;
}

String8 Duration::getName() const
{
	return name;
}

void Duration::setBegin( PreciseTime begin )
{
	this->begin = begin;
}

PreciseTime Duration::getBegin() const
{
	return begin;
}

void Duration::setLength( PreciseTime length )
{
	this->length = length;
}

PreciseTime Duration::getLength() const
{
	return length;
}

PreciseTime Duration::getEnd() const
{
	return begin + length;
}

void Duration::setup( PreciseTime begin , PreciseTime length , const String8& name )
{
	this->begin = begin;
	this->length = length;
	this->name = name;
}

} // time

