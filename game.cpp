/*
	ShiftingBricks: Game class file
*/

#include <sifteo.h>
#include "game.h"
#include "mapblock.h"

/* Set three cube objects to the game */
Game::Game()
: cube_0(0), cube_1(1), cube_2(2)
{}

/*
	Display game title for 3 seconds
*/
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

/*
	Initialize cubes and places player in cube(0)
*/
void Game::init(){
	for(unsigned i = 0; i < NUM_CUBES; i++){
		getCube(i).init();
	}

	plyr.init(&getCube(0));

	Events::neighborAdd.set(&Game::attachCube, this);
	Events::neighborRemove.set(&Game::detachCube, this);

}

/*
*	Runs physics for all cubes and player when called
*/
void Game::doPhysics() {
    for(unsigned i = 0; i < NUM_CUBES; i++){
		getCube(i).doPhysics();
	}

	plyr.doPhysics();
}

/*
*	Runs and updates physics and animation frames if player is alive
*/
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


/*
*	Function to tell two cubes are attached when they connect to eachother in real life
*/

void Game::attachCube(unsigned cube1, unsigned side1, unsigned cube2, unsigned side2){
	GameCube &gc1 = getCube(cube1);
	GameCube &gc2 = getCube(cube2);

	gc1.setTransition(side1, &gc2);
	gc2.setTransition(side2, &gc1);
}


/*
*	Function to tell two cubes are detached when they no longer connect to eachother in real life
*/
void Game::detachCube(unsigned cube1, unsigned side1, unsigned cube2, unsigned side2){
	GameCube &gc1 = getCube(cube1);
	GameCube &gc2 = getCube(cube2);

	gc1.closeTransition(side1);
	gc2.closeTransition(side2);
}


/*
*	Sets animation for all cubes
*/
void Game::animate(float td){
	for(unsigned i = 0; i < NUM_CUBES; i++){
		getCube(i).animate();
	}
}


/*
*	Visually draws for all cubes and player
*/
void Game::draw(){
    
    for(unsigned i = 0; i < NUM_CUBES; i++){
		getCube(i).draw();
	}

	plyr.draw();
}


/*
*	Removes all objects
*/
void Game::cleanup(){
	Events::neighborAdd.unset();
	Events::neighborRemove.unset();
}