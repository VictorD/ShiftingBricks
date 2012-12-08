/*
	ShiftingBricks:	SolidObject class file
*/

#include "solidobject.h"
#include "game.h"

void SolidObject::draw(VideoBuffer *vid) {
    vid->bg1.image(position, Grass);
}

void SolidObject::move() {
    position = vec(position.x + velocity.x, position.y + velocity.y + hasGravity());

    boundingBox.setPosition(position);
    if (BoundingBox::vectorLengthSquared(velocity) > 0)
        LOG("new position: %d, %d\n", position.x, position.y);
}

bool SolidObject::collidesWith(SolidObject *s2) {
    if (!hasGravity())
        return false;

    return collidesWith(s2->getBoundingBox());
}

bool SolidObject::collidesWith(BoundingBox b2) {
    return boundingBox.intersects(b2);
}

void SolidObject::handleCollision(SolidObject *s2) {
    Int2 collisionVector = boundingBox.getIntersection(s2->getBoundingBox());

    position = vec(position.x, position.y - collisionVector.y);
    LOG("collision! moved: %d, %d\n", collisionVector.x, collisionVector.y);
    
    if (!s2->hasGravity()) // We've landed on something that won't move.
        gravity = false;
}