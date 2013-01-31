/*
 * coreglfwcontext.hpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#ifndef GLFWCONTEXT_HPP_
#define GLFWCONTEXT_HPP_

#include <core/corecontext.hpp>

namespace glfw {

class Context : public core::Context
{
private:
	uint32 state;
	graphics::RenderTarget::Ptr rendertarget;

	core::Joystick::Map joystickMap;
	core::Keyboard::Map keyboardMap;
	core::Mouse::Map mouseMap;
	core::Touch::Map touchMap;
public:
	Context();
	virtual ~Context();

	virtual bool initialize( Json::ValuePtr& config );

	virtual void getRenderTarget( graphics::RenderTarget::Ptr& ptr );

	virtual void get( core::Joystick::Ptr& ptr , int number );
	virtual void get( core::Keyboard::Ptr& ptr , int number );
	virtual void get( core::Mouse::Ptr& ptr , int number );
	virtual void get( core::Touch::Ptr& ptr , int number );

	virtual int getJoystickCount();
	virtual int getKeyboardCount();
	virtual int getMouseCount();
	virtual int getTouchCount();
};

} // namespace glfw
#endif // GLFWCONTEXT_HPP_
