/*
 * applicationlistener.hpp
 *
 *  Created on: 17.1.2013
 *      Author: akin
 */

#ifndef APPLICATIONLISTENER_HPP_
#define APPLICATIONLISTENER_HPP_

#include <commontypes.h>

class ApplicationListener
{
public:
	ApplicationListener();
	virtual ~ApplicationListener();

	// Initializing
	virtual void processArgs( int argc , char *argv[] );
	virtual bool initialize();

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

#endif // APPLICATIONLISTENER_HPP_
