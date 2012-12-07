/*
	ShiftingBricks Header File
*/

#ifndef GAME_H
#define GAME_H

#include <sifteo.h>
#include "assets.gen.h"
#include "solidobject.h"
#include "mapblock.h"
#include "gamecube.h"
#include "player.h"

using namespace Sifteo;

#define NUM_CUBES	3	// For cubeRange
#define BLOCK_FORMS	1	// For testing purposes only one type of block


/*		Game class		*/

class BlockFactory{};

class Game{
public:
	Game();
	
	void title();
	void init();
	void run();
	void animate(float td);
	void attachCube();
	void detachCube();
	void draw();
    void doPhysics();
	void cleanup();
	
	Player plyr;
	
private:
	GameCube cube_0, cube_1, cube_2;
	GameCube &getCube(unsigned i){
		switch(i){
		default:
		case 0: return cube_0;
		case 1: return cube_1;
		case 2: return cube_2;
		};
	}
	
};


#endif
