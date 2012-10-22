/*
 * state.hpp
 *
 *  Created on: 17.6.2012
 *      Author: akin
 */

#ifndef STATE_STATE_HPP_
#define STATE_STATE_HPP_

namespace state {

class State
{
public:
	State();
	virtual ~State();

	virtual void activate() = 0;
	virtual void run() = 0;
	virtual bool canExit() = 0;
	virtual void exit() = 0;
};

} // namespace state
#endif // STATE_STATE_HPP_
