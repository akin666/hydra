/*
 * audiocontext.hpp
 *
 *  Created on: 25.1.2013
 *      Author: akin
 */

#ifndef AUDIOCONTEXT_HPP_
#define AUDIOCONTEXT_HPP_

#include <commontypes.h>
#include <input/inputmanager.hpp>
#include <json>

namespace audio {

class Context
{
public:
	typedef std::shared_ptr<Context> Ptr;
	typedef std::weak_ptr<Context> WeakPtr;
protected:
	input::Manager::Ptr& inputmanager;
public:
	Context( input::Manager::Ptr& inputmanager );
	virtual ~Context();

	virtual bool initialize( Json::ValuePtr& config ) = 0;
};

} // namespace audio 
#endif // AUDIOCONTEXT_HPP_ 
