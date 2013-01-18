/*
 * listenermouse.hpp
 *
 *  Created on: 19.1.2013
 *      Author: akin
 */

#ifndef LISTENERMOUSE_HPP_
#define LISTENERMOUSE_HPP_

#include "commontypes.h"

namespace listener {

class Mouse
{
public:
	Mouse();
	virtual ~Mouse();

	virtual void handleMouseMove( const int device , const float x , const float y );
	virtual void handleMouseButton( const int device , const Button button , const float state );
	virtual void handleMouseButtonAction( const int device , const Button button );
	virtual void handleMouseWheel( const int device , const float val );
};

} // namespace listener 
#endif // LISTENERMOUSE_HPP_ 
