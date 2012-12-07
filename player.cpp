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

}

void Player::animate(float dt){
	//Determine what animation should be drawn
}

void Player::draw(){
	if(animIndex < 4){animIndex = animIndex+1;}
	else{animIndex = 0;}
	const auto &sprite = onCube->vid.sprites[1];
	sprite.setImage(Atest, animIndex);
	sprite.move(10,20);
}
