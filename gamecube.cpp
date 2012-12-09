/*
	ShiftingBricks:	Game cube class file
*/

#include <sifteo.h>
#include "gamecube.h"

/*		Shamelessly stolen from example/membrane to init cubes	 */

GameCube::GameCube(CubeID cube)
{
	vid.attach(cube);
	bool Transitions[] = {0,0,0,0};
}

void GameCube::init(){
	vid.initMode(BG0);
    vid.bg0.image(vec(0,0), Background);	
}

void GameCube::draw(){
    vid.initMode(BG0_SPR_BG1);
	vid.bg0.image(vec(0,0), Background); 
    scene.draw(&vid);
}

void GameCube::animate(){
	
}

void GameCube::doPhysics() {
   scene.doPhysics();
}

void GameCube::setTransition(unsigned side){
	Transitions[side] = 1;
	LOG("Side: %d \n", Transitions[side]);
}

void GameCube::closeTransition(unsigned side){
	Transitions[side] = 0;
	LOG("Side: %d \n", Transitions[side]);
}

void GameCube::getNewPattern(){}
