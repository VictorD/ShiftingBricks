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
    getCube(0).scene.addObject(SolidObject(vec(4,3), vec(0,0), true, 4,2));
    getCube(0).scene.addObject(SolidObject(vec(6,0), vec(0,0), true, 4,2));
    getCube(0).scene.addObject(SolidObject(vec(0,11), vec(0,0), false, 16,4));
    getCube(1).scene.addObject(SolidObject(vec(0,11), vec(0,0), false, 11,4));
    getCube(2).scene.addObject(SolidObject(vec(0,11), vec(0,0), false, 11,4));
    
	for(unsigned i = 0; i < NUM_CUBES; i++){
		getCube(i).init();
	}
	
	plyr.init(&getCube(0));
	
}

void Game::doPhysics() {
    for(unsigned i = 0; i < NUM_CUBES; i++){
		getCube(i).doPhysics();
	}

	plyr.doPhysics();
	
	Events::neighborAdd.set(&Game::attachCube, this);
	Events::neighborRemove.set(&Game::detachCube, this);
}
void Game::run(){

	TimeStep ts;
	
	while(!plyr.isDead()){
		ts.next();
		
		//Run animation methods here
		animate(ts.delta());
		
		//Run physics with fixed timestep(To be decided)
		doPhysics();
		
		//Display on cubes
		draw();
		System::paint();
	}
}

void Game::attachCube(unsigned cube1, unsigned cube2, unsigned side1, unsigned side2){
	LOG("Perky");
}

void Game::detachCube(unsigned cube1, unsigned cube2, unsigned side1, unsigned side2){
	LOG("Nipples");
}

void Game::animate(float td){
	
	for(unsigned i = 0; i < NUM_CUBES; i++){
		getCube(i).animate();
	}
}

void Game::draw(){
    
    for(unsigned i = 0; i < NUM_CUBES; i++){
		getCube(i).draw();
	}
	
	plyr.draw();
}

void Game::cleanup(){}