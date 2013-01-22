/*
 * systemwindow.hpp
 *
 *  Created on: 23.1.2013
 *      Author: akin
 */

#ifndef COREWINDOW_HPP_
#define COREWINDOW_HPP_

#include <input/inputsource.hpp>

namespace core {

class Window
{
public:
	Window();
	virtual ~Window();

	virtual void get( const String8& name , input::Source::Ptr& ptr );
	virtual void get( input::Mode mode , input::Source::Ptr& ptr );
	virtual void get( input::Type type , input::Source::Ptr& ptr );
	virtual void clean();

	virtual void get( input::Mode& mode ) const;
	virtual void get( input::Type& mode ) const;
	virtual void get( StringSet& names ) const;

	// get graphics rendertarget from here
	// get graphics context also?
	// get audio context?
	// setup window with graphics settings.
	// query for window modes etc.
};

} // namespace core
#endif // COREWINDOW_HPP_
