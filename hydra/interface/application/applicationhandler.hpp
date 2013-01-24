/*
 * applicationhandler.hpp
 *
 *  Created on: 24.1.2013
 *      Author: akin
 */

#ifndef APPLICATIONHANDLER_HPP_
#define APPLICATIONHANDLER_HPP_

#include <commontypes.h>

namespace application {

class Handler
{
public:
	typedef std::shared_ptr<Handler> Ptr;
	typedef std::weak_ptr<Handler> WeakPtr;
public:
	Handler();
	virtual ~Handler();

	// Commands.
	virtual void suspend(); // suspend the application, going into background.
	virtual void resume();	// resume the application state
	virtual void exit();	// kill instruction
	virtual void restart(); // instruct the application to do hard restart

	virtual void minimize();
	virtual void maximize();

	virtual void windowed();
	virtual void fullscreened();

	virtual void lostFocus();

	virtual void memoryWarning( uint level = 0 ); // running out of memory.

	virtual void saveState(); // save config etc.

	// App exception handling
	virtual void handleException( std::exception& e );
	virtual void handleEllipsisException();
};

} // namespace application 
#endif // APPLICATIONHANDLER_HPP_ 
