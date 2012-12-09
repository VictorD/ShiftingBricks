/*
	ShiftingBricks:	Game cube class file
*/

#include <sifteo.h>
#include "gamecube.h"

/*		Shamelessly stolen from example/membrane to init cubes	 */

GameCube::GameCube(CubeID cube)
{
	vid.attach(cube);
	GameCube* Transitions[] = {NULL,NULL,NULL,NULL};
}

void GameCube::init(){
	vid.initMode(BG0);
    vid.bg0.image(vec(0,0), Background);
}

void GameCube::draw(){
    vid.initMode(BG0_SPR_BG1);
    bgPosition.x++;
    if (bgPosition.x > 144)
        bgPosition.x = 0;
        
    vid.bg0.setPanning(bgPosition);
	vid.bg0.image(vec(0,0), Background); 
    scene.draw(&vid);
}

void GameCube::animate(){
	
}

void GameCube::doPhysics() {
   scene.doPhysics();
}

void GameCube::setTransition(unsigned side, GameCube* gc){
	Transitions[side] = gc;
}

void GameCube::closeTransition(unsigned side){
	Transitions[side] = NULL;
}

void GameCube::getNewPattern(){}
