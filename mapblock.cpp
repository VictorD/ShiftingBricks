/*
	ShiftingBricks:	MapBlock class file
*/

#include <sifteo.h>
#include "game.h"
#include "mapblock.h"

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
        SolidObject *s = start+i;
        if (s->isAffectedByGravity()) {                
            s->move();
        }
    }  
}