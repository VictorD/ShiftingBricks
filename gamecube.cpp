/*
	ShiftingBricks:	Game cube class file
*/

#include <sifteo.h>
#include "gamecube.h"

/*		Shamelessly stolen from example/membrane to init cubes	 */

GameCube::GameCube(CubeID cube)
{
	vid.attach(cube);
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

void GameCube::getNewPattern(){}
