/*
	ShiftingBricks:	Game class file
*/

#include <sifteo.h>
#include "game.h"

Game::Game()
	: cube_0(0), cube_1(1), cube_2(2)
{}

void Game::title(){

	const float titleTime = 5.0f;
	SystemTime titleDeadline = SystemTime::now() + titleTime;
	vid.initMode(BG0);
	
	while(SystemTime::now() < titleDeadline){
		vid.bg0.image(vec(0,0), Title);
		System::paint();
	}
}

void Game::init(){}

void Game::run(){}

void Game::addBlock(){}

void Game::removeBlock(){}

void Game::draw(){}

void Game::cleanup(){}