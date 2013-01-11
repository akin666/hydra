//============================================================================
// Name        : Hello.cpp
// Author      : akin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <system.hpp>
#include "UI/uithread.hpp"

class DummyThread : public logic::Thread
{
public:
	DummyThread()
	{
	}

	virtual ~DummyThread()
	{
	}

	virtual bool run()
	{
		return true;
	}
};

int main()
{
	System system;

	do
	{
		if( !system.initialize() )
		{
			return -1;
		}

		system.createThread<DummyThread>();

		do
		{
			system.run();
		}
		while( !system.shouldExit() );

		system.uninitialize();
	}
	while( system.shouldRestart() );

	return 0;
}
