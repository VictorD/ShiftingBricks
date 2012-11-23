/*
	ShiftingBricks Header File
*/

#ifndef GAME_H
#define GAME_H

#include <sifteo.h>
#include "assets.gen.h"
#include "solidobject.h"

using namespace Sifteo;

#define NUM_CUBES	3	// For cubeRange
#define BLOCK_FORMS	1	// For testing purposes only one type of block


/*		Classes		*/

class GameCube{

public:
	GameCube(CubeID id);
	
	void init();
	void draw();
	void getNewPattern();
	
	VideoBuffer vid;
};

class Player{

public:
	Player();
	
	void spawn();
	void draw();
};

class MapBlock{};

class BlockFactory{};

class Game{

public:
	Game();
	
	void title();
	void init();
	void run();
	void addBlock();
	void removeBlock();
	void draw();
	void cleanup();
	
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
