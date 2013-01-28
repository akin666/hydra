/*
 * coremouse.hpp
 *
 *  Created on: 29.1.2013
 *      Author: akin
 */

#ifndef COREMOUSE_HPP_
#define COREMOUSE_HPP_

#include <commontypes.h>
#include <signal.h>

namespace core {

class Mouse
{
public:
	enum State{ UP = 0 , DOWN = 1 };

	typedef std::shared_ptr<Mouse> Ptr;
	typedef std::weak_ptr<Mouse> WeakPtr;
public:
	Mouse();
	~Mouse();

	signal::Signal2<float , float> move;
	signal::Signal2<int , State> button;
	signal::Signal1<float> wheel;
};

} // namespace core 
#endif // COREMOUSE_HPP_ 
