/*
 * inputlistener.h
 *
 *  Created on: 18.7.2011
 *      Author: akin
 *
 *  platform gets this object from the Singleton
 *  and sends events, using these functions.
 *  Whoever implements the interface, must be
 *  aware, that there is NO threading protection here,
 *  it might get called twice or thrillion times at once.
 */


#ifndef INPUTLISTENER_H_
#define INPUTLISTENER_H_

class InputListener
{
public:
	enum Button
	{
		LEFT,
		RIGHT,
		MIDDLE,
		ADDON_1,
		ADDON_2,
		ADDON_3,
		ADDON_4,
		ADDON_5,
		ADDON_6,
		ADDON_LAST
	};

	enum State
	{
		BEGIN,
		END,
		MOVED,
		CANCELLED
	};

	InputListener();
	virtual ~InputListener();

	virtual void handleMouseMove( const int device , const float x , const float y );
	virtual void handleMouseButton( const int device , const Button button , const float state );
	virtual void handleMouseButtonAction( const int device , const Button button );
	virtual void handleMouseWheel( const int device , const float val );
	virtual void handleJoystickMove( const int device , const float x , const float y );
	virtual void handleJoystickButton( const int device , const Button button , const float state );
	virtual void handleKeyboard( const int device , const unsigned int key , const float state );
	virtual void handleKeyboardCharacter( const int device , const unsigned int key , const float state );
	virtual void handleTouch( const int device , const float x , const float y , const State state , const float value );
};

#endif

