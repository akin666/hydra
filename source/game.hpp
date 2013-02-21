/*
 * game.hpp
 *
 *  Created on: 30.1.2013
 *      Author: akin
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include <protothread>
#include <hydramain.hpp>
#include <entity>

#include "graphicsobject.hpp"

class Game : public Protothread
{
private:
	entity::Context context;

	hydra::Main& main;
	Protothread::Ptr render;
public:
	Game( hydra::Main& main );
	virtual ~Game();

	glm::mat4 camera;
	GraphicsObject object;

	virtual bool run();
};

class GameRender : public Protothread
{
private:
	hydra::Main& main;
	Game& game;
public:
	GameRender( hydra::Main& main , Game& game );
	virtual ~GameRender();

	virtual bool run();
};


#endif // GAME_HPP_ 
