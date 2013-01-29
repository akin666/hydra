/*
 * userinterfacescheduler.hpp
 *
 *  Created on: 11.12.2012
 *      Author: akin
 */

#ifndef UITHREAD_HPP_
#define UITHREAD_HPP_

#include <entitylib/entitycontext.hpp>
#include <protothread>

#include "uifactory.hpp"

#include "property/uigraphics.hpp"
#include "property/uilocation.hpp"

namespace ui {

class Thread : public Protothread
{
private:
	unsigned int state;

	entity::Context context;

	GraphicsProperty& graphics;
	LocationProperty& location;

	Factory factory;
public:
	Thread();
	virtual ~Thread();

	void stop();

	virtual bool run();
};

} // namespace ui

#endif // UITHREAD_HPP_
