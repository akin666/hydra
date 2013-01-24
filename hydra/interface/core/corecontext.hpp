/*
 * corecontext.hpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#ifndef CORECONTEXT_HPP_
#define CORECONTEXT_HPP_

#include <commontypes.h>
#include <application/applicationmanager.hpp>
#include <input/inputmanager.hpp>
#include <graphics/graphicsrendertarget.hpp>s
#include <json>

namespace core {

class Context
{
public:
	typedef std::shared_ptr<Context> Ptr;
	typedef std::weak_ptr<Context> WeakPtr;
protected:
	application::Manager::Ptr& applicationmanager;
	input::Manager::Ptr& inputmanager;
public:
	Context( application::Manager::Ptr& applicationmanager , input::Manager::Ptr& inputmanager );
	virtual ~Context();

	virtual bool initialize( Json::ValuePtr& config ) = 0;

	virtual graphics::RenderTarget::Ptr getRenderTarget() = 0;
};

} // namespace core 
#endif // CORECONTEXT_HPP_ 
