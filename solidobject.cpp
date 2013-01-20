/*
	ShiftingBricks:	SolidObject class file
	
	The base class for solid objects
*/

#include "solidobject.h"
#include "game.h"

/* 
	Draw the solid object to the current videobuffer, vid.
 */
void SolidObject::draw(VideoBuffer *vid) {
    vid->bg1.image(position, Grass);
}

/* 
	Alter the current position of this solid.
 */
void SolidObject::move() {
    position = vec(position.x + velocity.x, position.y + velocity.y + hasGravity());
    boundingBox.setPosition(vec(8*position.x, 8*position.y));
    
    if (BoundingBox::vectorLengthSquared(velocity) > 0)
        LOG("new position: %d, %d\n", position.x, position.y);
}

/* 
	Test for collision, this method is called by the doPhysics() method in the game loop.
	Note: Only in effect if the object is currently affected by gravity.
 */
bool SolidObject::collidesWith(SolidObject *s2) {
    if (!hasGravity())
        return false;

    return collidesWith(s2->getBoundingBox());
}

bool SolidObject::collidesWith(BoundingBox b2) {
    return boundingBox.intersects(b2);
}

/* 
	OnCollision: stop the object from falling through the object it has landed on by 
				 turning gravity off.
 */
void SolidObject::handleCollision(SolidObject *s2) {
    Int2 collisionVector = boundingBox.getIntersection(s2->getBoundingBox());

    position = vec(position.x, position.y - collisionVector.y);
    LOG("collision! moved: %d, %d\n", collisionVector.x, collisionVector.y);
    
    if (!s2->hasGravity()) // We've landed on something that won't move.
        gravity = false;
}