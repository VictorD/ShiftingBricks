/*
	ShiftingBricks:	Game cube class file
*/

#include <sifteo.h>
#include "game.h"

/*		Shamelessly stolen from example/membrane to init cubes	 */

GameCube::GameCube(CubeID cube):
		/*	things each of our cubes will hold	*/

{
vid.attach(cube); // Assign a VideoBuffer to each cube
}

void GameCube::init(){}


void GameCube::draw(){}


void GameCube::getNewPattern(){}
