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
	void getNewPattern(int id);
	
	void setTransition(unsigned side, GameCube* gc);
	void closeTransition(unsigned side);
	
	GameCube* getTop(){ return Transitions[0]; };
	GameCube* getLeft(){ return Transitions[1]; };
	GameCube* getBottom(){ return Transitions[2]; };
	GameCube* getRight(){ return Transitions[3]; };
	
	VideoBuffer vid;
    MapBlock scene;
	
private:
	CubeID id;
	GameCube* Transitions[4];
    Int2 bgPosition;
};

#endif