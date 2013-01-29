//============================================================================
// Name        : Hello.cpp
// Author      : akin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <hydramain.hpp>
#include "UI/uithread.hpp"

class DummyThread : public Protothread
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
	hydra::Main main;

	do
	{
		if( !main.initialize() )
		{
			return -1;
		}

		main.createThread<DummyThread>();

		do
		{
			main.run();
		}
		while( !main.shouldExit() );

		main.uninitialize();
	}
	while( main.shouldRestart() );

	return 0;
}
