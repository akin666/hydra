/*
 * duration.hpp
 *
 *  Created on: 26.7.2012
 *      Author: akin
 */

#ifndef TIME_DURATION_HPP_
#define TIME_DURATION_HPP_

#include "time.hpp"

namespace time {

class Duration
{
protected:
	PreciseTime begin;
	PreciseTime length;
	String8 name;
public:
	Duration();

	void setName( const String8& name );
	String8 getName() const;

	void setBegin( PreciseTime begin );
	PreciseTime getBegin() const;

	void setLength( PreciseTime length );
	PreciseTime getLength() const;

	PreciseTime getEnd() const;

	void setup( PreciseTime begin , PreciseTime length , const String8& name );
};

} // time

#endif // DURATION_HPP_ 
