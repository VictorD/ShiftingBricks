/*
	ShiftingBricks:	Player class file
*/

#include <sifteo.h>
#include "player.h"

Player::Player()
	: onCube(0), animIndex(0)
{}

void Player::init(GameCube *gc){
	onCube = gc;

    collisionBox = SolidObject(vec(10,20), vec(0,0), true, 2,2);
    gc->scene.addObject(collisionBox);
}

void Player::animate(float dt){
	//Determine what animation should be drawn
}

void Player::draw(){
	if(animIndex < 72){animIndex++;}
	else{
	animIndex = 0;
	onCube = onCube+1;
	}
	const auto &sprite = onCube->vid.sprites[1];
	sprite.setImage(Atest);
	sprite.move(2*animIndex-8,30);
}
