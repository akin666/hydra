/*
 * stateset.hpp
 *
 *  Created on: 17.6.2012
 *      Author: akin
 */

#ifndef STATE_SET_HPP_
#define STATE_SET_HPP_

#include "state.hpp"
#include <uthread>

namespace state {

class Set
{
protected:
	typedef std::vector<State*> StateSet;
	StateSet states;
	StateSet activateList;

	std::mutex addmutex;

	void destroy( State *state );
public:
	Set();
	virtual ~Set();

	void run();

	// The allocation is managed by the stack, if you want to modify the thing, then use the returned reference.
	template <class CType>
	CType& push()
	{
		std::lock_guard<std::mutex> lock( addmutex );
		CType *tmp = new CType;

		activateList.push_back( tmp );

		return *tmp;
	}
};

} // namespace state
#endif // STATE_SET_HPP_
