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
	vid.bg0.image(vec(0,0), Background);
}
void GameCube::draw(){
    vid.initMode(BG0_SPR_BG1);
    vid.bg0.image(vec(0,0), Background);
    
    BG1Mask bitmask;
    for(unsigned i = 0; i < 1; i++) {
        SolidObject s = solid; //solids[i];
        bitmask = bitmask | BG1Mask::filled(vec(s.getX(),s.getY()), vec(s.getWidth(), s.getHeight()));
    }

    vid.bg1.setMask(bitmask);
    
    for(unsigned i = 0; i < 1; i++) {
        SolidObject s = solid;//solids[i];
        vid.bg1.image(vec(s.getX(),s.getY()), Grass);
    }
}

void GameCube::getNewPattern(){}
