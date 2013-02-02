/*
 * game.cpp
 *
 *  Created on: 30.1.2013
 *      Author: akin
 */

#include "game.hpp"

Game::Game( hydra::Main& main )
: main( main )
, render( new GameRender( main ) )
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

GameRender::GameRender( hydra::Main& main )
: main( main )
{
}

GameRender::~GameRender()
{
}

bool GameRender::run()
{
	return false;
}

