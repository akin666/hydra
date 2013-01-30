/*
 * corecontext.hpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#ifndef CORECONTEXT_HPP_
#define CORECONTEXT_HPP_

#include <commontypes.h>
#include <graphics/graphicsrendertarget.hpp>
#include <json>
#include "coremouse.hpp"
#include "corekeyboard.hpp"
#include "corejoystick.hpp"
#include "coretouch.hpp"

namespace core {

class Context
{
public:
	typedef std::shared_ptr<Context> Ptr;
	typedef std::weak_ptr<Context> WeakPtr;
public:
	Context();
	virtual ~Context();

	virtual bool initialize( Json::ValuePtr& config ) = 0;
	virtual void getRenderTarget( graphics::RenderTarget::Ptr& ptr ) = 0;

	virtual void get( Joystick::Ptr& ptr , int number = 0 );
	virtual void get( Keyboard::Ptr& ptr , int number = 0 );
	virtual void get( Mouse::Ptr& ptr , int number = 0 );
	virtual void get( Touch::Ptr& ptr , int number = 0 );
};

} // namespace core 
#endif // CORECONTEXT_HPP_ 
