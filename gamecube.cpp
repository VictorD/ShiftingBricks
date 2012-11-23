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
    SolidObject s = solid;
    solidMask = solidMask | BG1Mask::filled(vec(s.getX(),s.getY()), vec(s.getWidth(), s.getHeight()));

    vid.initMode(BG0_SPR_BG1);
	vid.bg0.image(vec(0,0), Background);    
}
void GameCube::draw(){
    vid.initMode(BG0_SPR_BG1);
    vid.bg0.image(vec(0,0), Background);

    vid.bg1.setMask(solidMask);
    
    SolidObject s = solid;
    vid.bg1.image(vec(s.getX(),s.getY()), Grass);
}

void GameCube::getNewPattern(){}
