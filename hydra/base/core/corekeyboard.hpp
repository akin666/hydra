/*
 * corekeyboard.hpp
 *
 *  Created on: 29.1.2013
 *      Author: akin
 */

#ifndef COREKEYBOARD_HPP_
#define COREKEYBOARD_HPP_

#include <commontypes.h>
#include <signal.h>

namespace core {

class Keyboard
{
public:
	enum State{ UP = 0 , DOWN = 1 };

	typedef std::shared_ptr<Keyboard> Ptr;
	typedef std::weak_ptr<Keyboard> WeakPtr;
public:
	Keyboard();
	~Keyboard();

	signal::Signal2<int , State> key;
	signal::Signal1<UNICODE> character;
	signal::Signal1<float> wheel;
};

} // namespace core 
#endif // COREKEYBOARD_HPP_ 
