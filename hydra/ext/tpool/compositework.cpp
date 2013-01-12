/*
 * CompositeWork.cpp
 *
 *  Created on: 26.1.2012
 *      Author: akin
 */

#include "compositework.hpp"

namespace tpool {

CompositeWork::CompositeWork()
: running( false )
{
}

CompositeWork::~CompositeWork()
{
}

void CompositeWork::setRunning( bool state )
{
	std::lock_guard<std::mutex> lock(mutex);
	running = state;
}

bool CompositeWork::getRunning()
{
	std::lock_guard<std::mutex> lock(mutex);
	return running;
}

bool CompositeWork::begin()
{
	return true;
}

void CompositeWork::run()
{
	setRunning( true );
	WorkPtr current;

	while( work.tryPop( current ) )
	{
		if( current )
		{
			if( current->begin() )
			{
				current->run();
				current->end();
			}
			else
			{
				work.push( current );
			}
		}
	}
	setRunning( false );
}

void CompositeWork::end()
{
}

bool CompositeWork::isRunning()
{
	return getRunning();
}

void CompositeWork::push( WorkPtr& work )
{
	this->work.push( work );
}

} // namespace tpool

