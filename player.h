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
    void doPhysics();
    void move(Int2 pos);
	bool isOnCube(GameCube *gc){
		return onCube == gc;
	}
    
    bool isDead() { return dead; }
	
private:
    Int2 position;
	Int2 velocity;
	GameCube *onCube;
    BoundingBox boundingBox;
	unsigned animIndex;
    bool dead = false;
    
    Int2 getNextPosition();
};

#endif