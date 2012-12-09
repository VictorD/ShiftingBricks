/*
	ShiftingBricks:	Player class file
*/

#include <sifteo.h>
#include "player.h"
#include "game.h" 

Player::Player()
	: position(vec(0,30)), onCube(0), boundingBox(position, vec(2,4)), animIndex(0) {}

void Player::init(GameCube *gc){
	onCube = gc;
}

void Player::animate(float dt){
	//Determine what animation should be drawn
}

void Player::draw(){
	const auto &sprite = onCube->vid.sprites[1];
	sprite.setImage(Hero, (position.x/2) % 4);
}

void Player::move(Int2 pos) {
    position = pos;
}

Int2 Player::getNextPosition() {
   if(position.x > 127) {
       onCube = onCube+1;
       position = vec(0, position.y);
   }
        
   if (position.y > 127) {
       LOG("y: %d\n", position.y);
       dead = true;
   }
    
   int xpos = position.x + 2;
   int ypos = position.y + 2;
   return vec(xpos, ypos);
}

void Player::doPhysics() {
    Int2 nextPosition = getNextPosition();
    boundingBox = BoundingBox(nextPosition, vec(12,30));

    // Test for collisions with scene solids
	SolidArray sceneSolids = onCube->scene.getSolids();
    SolidObject *start = sceneSolids.begin();
    for(int j = 0; j < sceneSolids.count(); j++) {           
        SolidObject *solid = start+j;
        BoundingBox solidBox = solid->getBoundingBox();
        Int2 intersection = solidBox.getIntersection(boundingBox);
        
        if (BoundingBox::vectorLengthSquared(intersection) > 1) {
            nextPosition = vec(nextPosition.x-1, nextPosition.y-3);
            LOG("player collision detected, %d\n", intersection.y);
        }
    }    
    
    move(nextPosition);
       
    const auto &sprite = onCube->vid.sprites[1];
    sprite.move(position.x, position.y);
}