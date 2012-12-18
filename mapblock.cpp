/*  
	ShiftingBricks:	MapBlock class file
*/

#include <sifteo.h>
#include "game.h"
#include "mapblock.h"

Random MapBlock::random;


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



void MapBlock::generate() {
	solids.clear();

	int groundWidth = random.randrange(4,16);

	int option = random.randint(0,7);
	switch(option) {
		case 0:
			addObject(SolidObject(vec(3,4), vec(0,0), true, 3,4));
			addObject(SolidObject(vec(0,6), vec(0,0), true, 2,2));
			addObject(SolidObject(vec(0,12), vec(0,0), false, 16,4));
		break;
		case 1:
			addObject(SolidObject(vec(7,4), vec(0,0), true, 3,3));
			addObject(SolidObject(vec(0,6), vec(0,0), true, 3,2));
			addObject(SolidObject(vec(2,12), vec(0,0), false, 6,4));
		break;
		case 2:

			addObject(SolidObject(vec(0,12), vec(0,0), false, 7,4));
		break;		
		case 3:
			addObject(SolidObject(vec(0,12), vec(0,0), false, 3,2));
			addObject(SolidObject(vec(2,10), vec(0,0), false, 3,2));
			addObject(SolidObject(vec(4,8), vec(0,0), false, 3,2));			
		break;
		case 4:
			addObject(SolidObject(vec(2,6), vec(0,0), false, 2,4));
			addObject(SolidObject(vec(6,3), vec(0,0), false, 4,2));
			addObject(SolidObject(vec(3,3), vec(0,0), false, 2,4));
		break;
		case 5:
			addObject(SolidObject(vec(0,4), vec(0,0), false, 2,2));
			addObject(SolidObject(vec(6,4), vec(0,0), false, 2,2));
			addObject(SolidObject(vec(4,12), vec(0,0), false, 12,4));
		break;
		case 6:
			addObject(SolidObject(vec(10,2), vec(0,0), false, 2,2));
			addObject(SolidObject(vec(8,4), vec(0,0), false, 2,2));
			addObject(SolidObject(vec(6,6), vec(0,0), false, 2,2));
		break;
		case 7:
			addObject(SolidObject(vec(4,4), vec(0,0), false, 12,2));
			addObject(SolidObject(vec(0,14), vec(0,0), false, 16,2));
		break;
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