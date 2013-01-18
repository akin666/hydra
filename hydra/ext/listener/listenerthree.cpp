/*
 * listenerthree.cpp
 *
 *  Created on: 19.1.2013
 *      Author: akin
 */

#include "listenerthree.hpp"
#include <commontypes.h>

namespace listener
{

Three::Three()
{
}

Three::~Three()
{
}

void Three::handleThreeMove( const int device , const float x , const float y , const float z )
{
	LOG->message( "%s:%i three %i at %dx%dxd" , __FILE__ , __LINE__ , device , x , y , z );
}

void Three::handleThreeButton( const int device , const Button button , const float state )
{
	LOG->message( "%s:%i three %i action %i went %d" , __FILE__ , __LINE__ , device , button , state );
}

} // namespace listener 
