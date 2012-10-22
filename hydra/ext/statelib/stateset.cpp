/*
 * statestack.cpp
 *
 *  Created on: 17.6.2012
 *      Author: akin
 */

#include "stateset.hpp"
#include <deque>

namespace state {

Set::Set()
{
}

Set::~Set()
{
	// Destroy the states
	for( StateSet::iterator iter = activateList.begin() ; iter != activateList.end() ; ++iter )
	{
		State *current = *this;
		current->exit();
		destroy( current );
	}
	activateList.clear();

	for( StateSet::iterator iter = states.begin() ; iter != states.end() ; ++iter )
	{
		State *current = *iter;
		current->exit();
		destroy( current );
	}
	states.clear();
}

void Set::destroy( State *state )
{
	if( state != NULL )
	{
		delete state;
	}
}

void Set::run()
{
	// Creation activation.
	if( activateList.size() > 0 )
	{
		StateSet tmplist;
		// critical section, copies the activatelist.
		{
			std::lock_guard<std::mutex> lock( addmutex );
			tmplist = activateList;
			activateList.clear();
		}

		for( StateSet::iterator iter = tmplist.begin() ; iter != tmplist.end() ; ++iter )
		{
			State *current = *this;
			current->activate();

			states.push_back( current );
		}
	}

	StateSet::iterator tmp;
	for( StateSet::iterator iter = states.begin() ; iter != states.end() ; ++iter )
	{
		State *current = *iter;
		current->run();

		if( current->canExit() )
		{
			current->exit();
			destroy( current );
			tmp = iter;
			// reverse iter by one
			--iter;
			// kill tmp, iterators after tmp are invalidated now. ++iter in loop advances correctly to next.
			states.erase( tmp );
		}
	}
}

} // namespace orion
