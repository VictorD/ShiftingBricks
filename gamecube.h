/*
	Game Cube Header File
*/

#ifndef _GAME_CUBE_
#define _GAME_CUBE_

#include <sifteo.h>
#include "mapblock.h"
#include "assets.gen.h"

class GameCube{

public:
	GameCube(CubeID id);
	
	void init();
	void draw();
	void animate();
    void doPhysics();
	void getNewPattern();
	
	VideoBuffer vid;
    MapBlock scene;
};

#endif