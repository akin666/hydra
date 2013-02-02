/*
 * corekeyboard.hpp
 *
 *  Created on: 29.1.2013
 *      Author: akin
 */

#ifndef COREKEYBOARD_HPP_
#define COREKEYBOARD_HPP_

#include "corecommon.hpp"
#include <signal.h>

namespace core {

class Keyboard
{
public:
	typedef std::shared_ptr<Keyboard> Ptr;
	typedef std::weak_ptr<Keyboard> WeakPtr;
	typedef std::map<int , Ptr> Map;
public:
	Keyboard();
	~Keyboard();

	signal::Signal2<int , ButtonState> key;
	signal::Signal2<UNICODE , ButtonState> character;
	signal::Signal1<float> wheel;
};

} // namespace core 
#endif // COREKEYBOARD_HPP_ 
