/*
 * listenertouch.hpp
 *
 *  Created on: 19.1.2013
 *      Author: akin
 */

#ifndef LISTENERTOUCH_HPP_
#define LISTENERTOUCH_HPP_

#include "listenercommon.hpp"

namespace listener {

class Touch
{
public:
	Touch();
	virtual ~Touch();

	void handleTouchBegin( const int device , const float x , const float y );
	void handleTouchMoved( const int device , const float x , const float y );
	void handleTouchEnded( const int device , const float x , const float y );
	void handleTouchCancelled( const int device , const float x , const float y );

};

} // namespace listener 
#endif // LISTENERTOUCH_HPP_ 
