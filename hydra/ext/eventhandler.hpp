/*
 * eventhandler.hpp
 *
 *  Created on: 6.3.2013
 *      Author: akin
 */

#ifndef EVENTHANDLER_HPP_
#define EVENTHANDLER_HPP_

#include <vector>
#include <singleton>

template <class CType>
class EventListener
{
public:
	virtual ~EventListener()
	{
	}

	virtual void handle( const CType& event ) = 0;
};

template <class CType>
class EventHandler
{
private:
	std::vector< EventListener<CType>* > listeners;
public:
	void add( EventListener<CType> *ptr )
	{
		for( auto iter = listeners.begin() ; iter != listeners.end() ; ++iter )
		{
			if( *iter == ptr )
			{
				return;
			}
		}
		listeners.push_back( ptr );
	}

	void remove( EventListener<CType> *ptr )
	{
		for( auto iter = listeners.begin() ; iter != listeners.end() ; ++iter )
		{
			if( *iter == ptr )
			{
				listeners.erase( iter );
				return;
			}
		}
	}

	void dispatchDirect( const CType& event )
	{
		for( auto iter = listeners.begin() ; iter != listeners.end() ; ++iter )
		{
			(*iter)->handle( event );
		}
	}
};

template <class CType> void dispatch( const CType& msg )
{
	createSingleton< EventHandler<CType> >()->dispatchDirect( msg );
}

template <class CType> void connect( EventListener<CType> *ptr )
{
	createSingleton< EventHandler<CType> >()->add( ptr );
}

template <class CType> void disconnect( EventListener<CType> *ptr )
{
	createSingleton< EventHandler<CType> >()->remove( ptr );
}

#endif // EVENTHANDLER_HPP_
