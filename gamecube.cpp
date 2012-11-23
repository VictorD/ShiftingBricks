/*
	ShiftingBricks:	Game cube class file
*/

#include <sifteo.h>
#include "game.h"

/*		Shamelessly stolen from example/membrane to init cubes	 */

GameCube::GameCube(CubeID cube)
{
	vid.attach(cube);
}

void GameCube::init(){
	vid.initMode(BG0_SPR_BG1);
	vid.bg1.setMask(BG1Mask::filled(vec(0,11), vec(4,4)) | BG1Mask::filled(vec(6,5), vec(4,4)) | BG1Mask::filled(vec(2,2), vec(4,4)));
	vid.bg1.image(vec(0,11), Grass);
    vid.bg1.image(vec(2,2), Grass);
    vid.bg1.image(vec(6,5), Grass);
	vid.bg0.image(vec(0,0), Background);
}
void GameCube::draw(){}
void GameCube::getNewPattern(){}
