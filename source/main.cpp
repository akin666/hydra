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

#include "game.hpp"

#include <cstdlib>

void f1()
{
	std::cout << "Exitted" << std::endl;
}

int main()
{
	hydra::Main main;

	std::atexit( f1 );
	do
	{
		if( !main.initialize() )
		{
			return -1;
		}

		// Create game
		{
			Protothread::Ptr game;

			Game *raw = new Game( main );
			game = Protothread::Ptr( raw );

			main.schedule( game );
		}

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
