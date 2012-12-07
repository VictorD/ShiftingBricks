/*
	Player class Header File
*/


#ifndef PLAYER_H
#define PLAYER_H

#include "gamecube.h"

class Player{

public:
	Player();
	
	void init(GameCube *gc);
	void animate(float dt);
	void draw();
	bool isOnCube(GameCube *gc){
		return onCube == gc;
	}
	
private:
	GameCube *onCube;
    SolidObject collisionBox;
	unsigned animIndex;
};

#endif