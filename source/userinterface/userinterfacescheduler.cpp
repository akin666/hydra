/*
 * userinterfacescheduler.cpp
 *
 *  Created on: 11.12.2012
 *      Author: akin
 */

#include "userinterfacescheduler.hpp"

#define STATE_NONE 0x0000
#define STATE_EXIT 0x0001

UserInterfaceScheduler::UserInterfaceScheduler( entity::Context& context )
: state( STATE_NONE )
, graphics( context.get<GraphicsProperty>() )
, location( context.get<LocationProperty>() )
{
}

UserInterfaceScheduler::~UserInterfaceScheduler()
{
}

void UserInterfaceScheduler::stop()
{
	state |= STATE_EXIT;
}

bool UserInterfaceScheduler::run()
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

