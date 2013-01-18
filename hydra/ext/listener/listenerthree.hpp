/*
 * listenerthree.hpp
 *
 *  Created on: 19.1.2013
 *      Author: akin
 */

#ifndef LISTENERTHREE_HPP_
#define LISTENERTHREE_HPP_

#include "listenercommon.hpp"

namespace listener {

class Three
{
public:
	Three();
	virtual ~Three();

	virtual void handleThreeMove( const int device , const float x , const float y , const float z );
	virtual void handleThreeButton( const int device , const Button button , const float state );
};

} // namespace listener 
#endif // LISTENERTHREE_HPP_ 
