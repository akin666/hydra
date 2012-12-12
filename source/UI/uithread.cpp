/*
 * userinterfacescheduler.cpp
 *
 *  Created on: 11.12.2012
 *      Author: akin
 */

#include "uithread.hpp"

#define STATE_NONE 0x0000
#define STATE_EXIT 0x0001

namespace ui {

Thread::Thread()
: state( STATE_NONE )
, graphics( context.get<GraphicsProperty>() )
, location( context.get<LocationProperty>() )
, factory( context )
{
}

Thread::~Thread()
{
}

void Thread::stop()
{
	state |= STATE_EXIT;
}

bool Thread::run()
{
	PT_BEGIN();
	while( (state & STATE_EXIT) == 0 )
	{
		// Update entity context stuffs
		// Generate draws from graphics, and send to graphics pipeline..
		PT_YIELD();
	}
	PT_END();
}

} // namespace ui
