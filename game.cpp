/*
	ShiftingBricks:	Game class file
*/

#include <sifteo.h>
#include "game.h"
#include "mapblock.h"

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
    getCube(0).scene.addObject(SolidObject(vec(0,11), vec(0,0), true, 4,4));
    getCube(0).scene.addObject(SolidObject(vec(11,2), vec(0,0), true, 4,3));
    getCube(0).scene.addObject(SolidObject(vec(7,2), vec(0,0), false, 4,3));
    
    getCube(1).scene.addObject(SolidObject(vec(2,5), vec(0,0), false, 4,5));
    getCube(1).scene.addObject(SolidObject(vec(8,2), vec(0,0), true, 4,4));
    
    getCube(2).scene.addObject(SolidObject(vec(1,5), vec(0,0), true, 11,5));
    
	for(unsigned i = 0; i < NUM_CUBES; i++){
		getCube(i).init();
	}
}

void Game::doPhysics() {
    for(unsigned i = 0; i < NUM_CUBES; i++){
		getCube(i).doPhysics();
	}
}

void Game::run(){}

void Game::addBlock(){}

void Game::removeBlock(){}

void Game::draw(){
    
    for(unsigned i = 0; i < NUM_CUBES; i++){
		getCube(i).draw();
	}
    System::paint();
}

void Game::cleanup(){}