/*
 * random.hpp
 *
 *  Created on: 25.7.2012
 *      Author: akin
 */

#ifndef RANDOM_123HPP_
#define RANDOM_123HPP_

#include <cstdlib>
#include <stdtypes>

template <class CType>
CType random()
{
	return rand() % std::numeric_limits<CType>::max();
}

template <> float32 random();
template <> float64 random();

template <class CType>
CType random( const CType min , const CType max )
{
	CType diff = max - min;
	return (min + (rand() % diff)) % std::numeric_limits<CType>::max();
}

template <> float32 random( const float32 min , const float32 max );
template <> float64 random( const float64 min , const float64 max );

#endif // RANDOM_HPP_ 
