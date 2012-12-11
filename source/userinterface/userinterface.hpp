/*
 * userinterface.hpp
 *
 *  Created on: 11.12.2012
 *      Author: akin
 */

#ifndef USERINTERFACE_HPP_
#define USERINTERFACE_HPP_

#include <entitylib/entitycontext.hpp>
#include "userinterfacescheduler.hpp"
#include "userinterfacefactory.hpp"

class UserInterface
{
private:
	entity::Context context;
	UserInterfaceScheduler scheduler;
	UserInterfaceFactory factory;
public:
	UserInterface();
	~UserInterface();
};

#endif // USERINTERFACE_HPP_
