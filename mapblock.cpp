/*  
	ShiftingBricks:	MapBlock class file
*/

#include <sifteo.h>
#include "game.h"
#include "mapblock.h"

/* 
 * Draw the collidables that exist in this mapblock.
 */ 
void MapBlock::draw(VideoBuffer* vid) {
    BG1Mask solidMask = BG1Mask::empty();
    
    SolidObject *start = solids.begin();
    for(int i = 0; i < solids.count(); i++) {
        SolidObject *s = start+i;
        solidMask = solidMask | BG1Mask::filled(s->getPosition(), s->getSize());
    }
    vid->bg1.setMask(solidMask);

    for(int i = 0; i < solids.count(); i++) {
		SolidObject *s = start+i;
		s->draw(vid);
    }  
}

void MapBlock::doPhysics() {
    SolidObject *start = solids.begin();
    for(int i = 0; i < solids.count(); i++) {
        SolidObject *s1 = start+i;
        s1->move();

        // Test for collisions with other solids
        for(int j = 0; j < solids.count(); j++) {
            if (j == i) // Don't test solid collision with itself.
                continue;
                
            SolidObject *s2 = start+j;
            if (s1->hasGravity() && s1->collidesWith(s2)) {
                s1->handleCollision(s2);
                LOG("collision detected\n");
            }
        }
    }  
}