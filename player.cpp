/*
	ShiftingBricks:	Player class file
*/

#include <sifteo.h>
#include "player.h"
#include "game.h" 

/* Start values for the player object */
Player::Player()
	: position(vec(0,50)), velocity(vec(4,0)), onCube(0), boundingBox(position, vec(2,4)), animIndex(0) {}

void Player::init(GameCube *gc){
	onCube = gc;
}

/* Currently not used, will be used to isolate code for smoother animations */
void Player::animate(float dt){
	//Determine what animation should be drawn
}

/* Draws the player at the location he is currently at */
void Player::draw(){
	const auto &sprite = onCube->vid.sprites[1];
	sprite.move(position.x, position.y);
	sprite.setImage(Hero, (animIndex++)/2);
	if (animIndex == 6)
		animIndex = 0;
}

/* Set function for player location */
void Player::move(Int2 pos) {
    position = pos;
}

/* Function that returns a vector(Int2) for where the player should be next, this is used for screen transitions */
Int2 Player::getNextPosition() {
   if(position.x > 127) {
		// Check that right cube is connected, and check if the right cubes left side is the current cube
		if(onCube->getRight() != NULL && onCube->getRight()->getLeft() == onCube){
			/* Change cube which player is on */
			position = vec(0, position.y);
			onCube->getNewPattern(9);
			onCube = onCube->getRight();
		}
		else{
			dead = true;
		}
   }
       // Check that buttom cube is connected, and check if the buttom cubes top side is the current cube
   if (position.y > 127) {	
      LOG("y: %d\n", position.y);
	  if(onCube->getBottom() != NULL && onCube->getBottom()->getTop() == onCube){
		/* Change cube which player is on */
	     onCube->getNewPattern(9);
	     onCube = onCube->getBottom();
		 position = vec(position.x, 0);
	  }
	  else{
	     dead = true;
	  }
   }
   /* If player was not transitioning the new position is returned on the same cube */ 
   int xpos = position.x + velocity.x;
   int ypos = position.y + velocity.y;
   return vec(xpos, ypos);
}

/* Handles the player physics, if falling or if colliding with a solid object, uses boundingbox class to determine this */
void Player::doPhysics() {
    Int2 nextPosition = getNextPosition();
    boundingBox = BoundingBox(nextPosition, vec(12,30));

	bool falling = true;
    // Test for collisions with scene solids
	SolidArray sceneSolids = onCube->scene.getSolids();
    SolidObject *start = sceneSolids.begin();
    for(int j = 0; j < sceneSolids.count(); j++) {           
        SolidObject *solid = start+j;
        BoundingBox solidBox = solid->getBoundingBox();
        Int2 intersection = solidBox.getIntersection(boundingBox);
        
        if (BoundingBox::vectorLengthSquared(intersection) > 1) {
			falling = false;
	
			if (velocity.x == 1)
				velocity = vec(4, velocity.y);
				
			velocity = vec(velocity.x, 0);
            nextPosition = vec(nextPosition.x-1, nextPosition.y-3);
            //LOG("player collision detected, %d\n", intersection.y);
        }
    }    
    if (falling && velocity.y < 8) 
		velocity = vec(1, velocity.y + 2);
		
    move(nextPosition);
}