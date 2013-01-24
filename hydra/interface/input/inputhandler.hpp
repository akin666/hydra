/*
 * inputhandler.hpp
 *
 *  Created on: 22.1.2013
 *      Author: akin
 */

#ifndef INPUTHANDLER_HPP_
#define INPUTHANDLER_HPP_

#include "inputcommon.hpp"

namespace input {

class Handler
{
public:
	typedef std::shared_ptr<Handler> Ptr;
	typedef std::weak_ptr<Handler> WeakPtr;
public:
	virtual ~Handler();

	virtual void handleButton( uint32 id , float state );
	virtual void handleCharacter( uint32 id , float state );
	virtual void handleMove( uint32 id , float x , State state );
	virtual void handleMove( uint32 id , float x , float y , State state );
	virtual void handleMove( uint32 id , float x , float y , float z , State state );
};

} // namespace input 
#endif // INPUTHANDLER_HPP_
