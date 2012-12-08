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
	sprite.setImage(Hero, position.x % 4);
}

void Player::move() {
    position = getNextPosition();
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
    
   int xpos = position.x + 1;
   int ypos = position.y + 2;
   return vec(xpos, ypos);
}

void Player::doPhysics() {
    Int2 nextPosition = getNextPosition();
    Int2 boxPosition = vec(nextPosition.x/8, nextPosition.y/8);
    boundingBox = BoundingBox(boxPosition, vec(2,4));

    bool touchingGround = false;
    // Test for collisions with scene solids
	SolidArray sceneSolids = onCube->scene.getSolids();
    SolidObject *start = sceneSolids.begin();
    for(int j = 0; j < sceneSolids.count(); j++) {           
        SolidObject *solid = start+j;
        BoundingBox solidBox = solid->getBoundingBox();
        Int2 intersection = solidBox.getIntersection(boundingBox);
        
        //LOG("bb %d, %d\n", boundingBox.getPosition().x, boundingBox.getPosition().y);
        //LOG("sb %d, %d\n", solidBox.getPosition().x, solidBox.getPosition().y);
        //LOG("intersection %d, %d\n", intersection.x, intersection.y);
        
        if (BoundingBox::vectorLengthSquared(intersection) > 0) {
            touchingGround = true;
            position = vec(nextPosition.x, position.y - intersection.y);
            LOG("player collision detected, %d\n", intersection.y);
        }
    }    

    if (!touchingGround)
        move();
       
    const auto &sprite = onCube->vid.sprites[1];
    sprite.move(position.x, position.y);
}