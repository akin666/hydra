/*
 * game.cpp
 *
 *  Created on: 30.1.2013
 *      Author: akin
 */

#include "game.hpp"
#include <stdgl>
#include <random.hpp>

Game::Game( hydra::Main& main )
: main( main )
, render( new GameRender( main , *this ) )
{
}

Game::~Game()
{
}

bool Game::run()
{
	render::Scheduler::Ptr ptr;

	main.get( ptr );

	if( ptr )
	{
		ptr->add( render );

		// Allow finish rendering.
		ptr->finish();
	}

	return false;
}

GameRender::GameRender( hydra::Main& main , Game& game )
: main( main )
, game( game )
{
}

GameRender::~GameRender()
{
}

bool GameRender::run()
{
	glClearColor( 0.2f , 0.6f , random<float32>( 0.8f , 1.0f ) , 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
	return false;
}

