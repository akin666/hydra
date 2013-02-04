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
protected:
	static const std::string PATH;
public:
	typedef std::shared_ptr<Context> Ptr;
	typedef std::weak_ptr<Context> WeakPtr;
public:
	Context();
	virtual ~Context();

	// Application handling.
	signal::Signal0<void> suspend;
	signal::Signal0<void> resume;
	signal::Signal0<void> exit;
	signal::Signal0<void> restart;
	signal::Signal0<void> minimize;
	signal::Signal0<void> maximize;
	signal::Signal2<int,int> resize;
	signal::Signal0<void> windowed;
	signal::Signal0<void> fullscreened;
	signal::Signal0<void> lostFocus;

	signal::Signal1<int> memoryWarning;
	signal::Signal0<void> saveState;

	// App exception handling
	virtual void handleException( std::exception& e );
	virtual void handleEllipsisException();

	virtual void get( Joystick::Ptr& ptr , int number = 0 );
	virtual void get( Keyboard::Ptr& ptr , int number = 0 );
	virtual void get( Mouse::Ptr& ptr , int number = 0 );
	virtual void get( Touch::Ptr& ptr , int number = 0 );

	virtual int getJoystickCount();
	virtual int getKeyboardCount();
	virtual int getMouseCount();
	virtual int getTouchCount();

	virtual bool initialize( Json::ValuePtr& config ) = 0;
	virtual void getRenderTarget( graphics::RenderTarget::Ptr& ptr ) = 0;

	virtual void present() = 0;
};

} // namespace core 
#endif // CORECONTEXT_HPP_ 
