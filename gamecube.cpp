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
	vid.initMode(BG0);
	vid.bg0.image(vec(0,0), Background);
}
void GameCube::draw(){}
void GameCube::getNewPattern(){}
