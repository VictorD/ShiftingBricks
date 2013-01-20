/*
	ShiftingBricks:	Game cube class file
*/

#include <sifteo.h>
#include "gamecube.h"

/*		Shamelessly stolen from example/membrane to init cubes	 */

GameCube::GameCube(CubeID cube)
{	
	id = cube;
	vid.attach(cube);
	GameCube* Transitions[] = {NULL,NULL,NULL,NULL};
}

/* 
	Initialize the video buffer, the background image and the terrain for the scene.
*/
void GameCube::init(){
	vid.initMode(BG0);
    vid.bg0.image(vec(0,0), Background);
	getNewPattern(id);
}

/* 
	Draw the cloud background and the scene owned by this game cube
*/
void GameCube::draw(){
    vid.initMode(BG0_SPR_BG1);
    bgPosition.x++;
    if (bgPosition.x > 144)
        bgPosition.x = 0;
        
    vid.bg0.setPanning(bgPosition);
	vid.bg0.image(vec(0,0), Background); 
    scene.draw(&vid);
}

void GameCube::animate(){}

void GameCube::doPhysics() {
   scene.doPhysics();
}

void GameCube::setTransition(unsigned side, GameCube* gc){
	Transitions[side] = gc;
}

void GameCube::closeTransition(unsigned side){
	Transitions[side] = NULL;
}

/*
   getNewPattern: generates a new terrain pattern for the cube. 
   
   option  = 0 Means we want the default terrain of one single ground block
   option != 0 Means we randomize a terrain block. 

	The randomization has currently been modified to be semi-random to simplify testing, 
	with tiles randomized from a list of pre-generated tiles that have been proven to work well.
  
 */
void GameCube::getNewPattern(int option){
	if (option == 0) 
		scene.addObject(SolidObject(vec(0,12), vec(0,0), false, 16,4));
	else
		scene.generate();
}
