#ifndef _MAP_SCENE_
#define _MAP_SCENE_

#include <sifteo.h>
#include <sifteo/array.h>
#include "solidobject.h"

typedef Array<SolidObject, 8> SolidArray;

class MapBlock {
    
    public:
        void addObject(SolidObject s) {
            solids.append(s);
        }

        void init();
        void doPhysics();
        void draw(VideoBuffer* vid);
        SolidArray getSolids() { return solids; }
        
    private:
        int current = 0;
        SolidArray solids;
};

#endif