/*
	ShiftingBricks Header File
*/

#include "sifteo.h"
#include "assets.gen.h"

using namespace Sifteo;

#define NUM_CUBES	3	// Flexible way of setting amount of cubes
#define BLOCK_FORMS	1	// For testing purposes only one type of block


/*		Classes		*/

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
	
};

class GameCube{

public:
	GameCube(CubeID id);
	
	void init();
	void draw();
	void getNewPattern();

};

class Player{

public:
	Player();
	
	void spawn();
	void draw();
};

class MapBlock{};

class BlockFactory{};

class SolidObject{};

