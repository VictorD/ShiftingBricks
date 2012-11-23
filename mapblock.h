#ifndef _MAP_SCENE_
#define _MAP_SCENE_

#include <sifteo.h>
#include <sifteo/array.h>

class MapBlock {
    
    public:
        void addObject(SolidObject s) {
            solids.append(s);
        }
        
        
        void init();
        void doPhysics();
        void draw(VideoBuffer* vid);
        
    private:
        int current = 0;

        Array<SolidObject, 8> solids;
};

#endif