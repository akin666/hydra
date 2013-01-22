/*
 * inputdevice.hpp
 *
 *  Created on: 22.1.2013
 *      Author: akin
 */

#ifndef INPUTDEVICE_HPP_
#define INPUTDEVICE_HPP_

#include "inputcommon.hpp"

namespace input {

class Device
{
public:
	typedef std::shared_ptr<Device> Ptr;
	typedef std::weak_ptr<Device> WeakPtr;
public:
	virtual ~Device();

	virtual void handleButton( uint32 id , float state );
	virtual void handleCharacter( uint32 id , float state );
	virtual void handleMove( uint32 id , float x , State state );
	virtual void handleMove( uint32 id , float x , float y , State state );
	virtual void handleMove( uint32 id , float x , float y , float z , State state );
};

} // namespace input 
#endif // INPUTDEVICE_HPP_ 
