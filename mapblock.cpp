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
        solidMask = solidMask | BG1Mask::filled(vec(s->getX(),s->getY()), vec(s->getWidth(), s->getHeight()));
    }
    vid->bg1.setMask(solidMask);

    for(int i = 0; i < solids.count(); i++) {
        SolidObject *s = start+i;
        vid->bg1.image(vec(s->getX(),s->getY()), Grass);
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
            if (s2->testCollision(s1)) {
                s1->collidesWith(s2);
                LOG("collision\n");
            }
        }
    }  
}