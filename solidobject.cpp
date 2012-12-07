/*
	ShiftingBricks:	SolidObject class file
*/

#include "solidobject.h"
#include "game.h"

void SolidObject::draw(VideoBuffer *vid) {
	vid->bg1.image(position, Grass);
}

void SolidObject::move() {
    int gravity =  hasGravity;
    position = vec(position.x + velocity.x, position.y + velocity.y + gravity);
    
    if (vectorLengthSquared(velocity) > 0)
        LOG("new position: %d, %d\n", position.x, position.y);
}


void SolidObject::collidesWith(SolidObject *s2) {
    Int2 p1 = getPosition();
    Int2 p2 = s2->getPosition();
    Int2 size1 = getSize();
    Int2 size2 = s2->getSize();

    Int2 collisionVector = getRectCollisionVector(p1, size1, p2, size2);
    
    // There exists an area of overlap.
    if (vectorLengthSquared(collisionVector) > 0) {
        position = vec(position.x, position.y - collisionVector.y);
        LOG("collision! moved: %d, %d\n", collisionVector.x, collisionVector.y);
        if (!s2->isAffectedByGravity())
            hasGravity = false;
    }
}

bool SolidObject::testCollision(SolidObject *s2) {
    if (!hasGravity)
        return false;
        
    Int2 p1 = getPosition();
    Int2 p2 = s2->getPosition();
    Int2 size1 = getSize();
    Int2 size2 = s2->getSize();
    
    Int2 collisionVector = getRectCollisionVector(p1, size1, p2, size2);
    return vectorLengthSquared(collisionVector) > 0;
}
