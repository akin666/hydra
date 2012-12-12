/*
 * userinterfacescheduler.hpp
 *
 *  Created on: 11.12.2012
 *      Author: akin
 */

#ifndef USERINTERFACESCHEDULER_HPP_
#define USERINTERFACESCHEDULER_HPP_

#include <protothread>
#include <entitylib/entitycontext.hpp>

#include "property/graphics.hpp"
#include "property/location.hpp"

class UserInterfaceScheduler : public Protothread
{
private:
	unsigned int state;
	GraphicsProperty& graphics;
	LocationProperty& location;
public:
	UserInterfaceScheduler( entity::Context& context );
	virtual ~UserInterfaceScheduler();

	void stop();

	virtual bool run();
};

#endif // USERINTERFACESCHEDULER_HPP_
