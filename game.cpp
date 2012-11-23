/*
	ShiftingBricks:	Game class file
*/

#include <sifteo.h>
#include "game.h"

Game::Game()
	: cube_0(0), cube_1(1), cube_2(2)
{}

void Game::title(){

	const float titleTime = 3.0f;
	SystemTime titleDeadline = SystemTime::now() + titleTime;
	
	for(CubeID i = 0; i < NUM_CUBES; i++){
			getCube(i).vid.initMode(BG0);
		}
	
	while(SystemTime::now() < titleDeadline){
		for(CubeID i = 0; i < NUM_CUBES; i++){
			getCube(i).vid.bg0.image(vec(0,0), Title);
		}
		System::paint();
	}
}

void Game::init(){  
	for(unsigned i = 0; i < NUM_CUBES; i++){
		getCube(i).init();
	}
    
    getCube(0).solid = SolidObject(vec(2,2), vec(0,0), true, 4,4);
    getCube(1).solid = SolidObject(vec(5,5), vec(0,0), true, 4,4);
    getCube(2).solid = SolidObject(vec(1,5), vec(0,0), true, 4,4);
   /* 
    getCube(1).solids[0] = SolidObject(vec(2,2), vec(0,0), true, 2,2);
    getCube(1).solids[1] = SolidObject(vec(4,3), vec(0,0), true, 2,2);
    
    getCube(2).solids[0] = SolidObject(vec(2,2), vec(0,0), true, 1,1);
    getCube(2).solids[1] = SolidObject(vec(4,3), vec(0,0), true, 1,1);*/
}

void Game::run(){}

void Game::addBlock(){}

void Game::removeBlock(){}

void Game::draw(){
    
    for(unsigned i = 0; i < NUM_CUBES; i++){
		getCube(i).draw();
        System::paint();
        System::finish();
	}
    
}

void Game::cleanup(){}