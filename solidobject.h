#ifndef _SOLIDOBJECT_H_
#define _SOLIDOBJECT_H_
#include <sifteo.h>
#include "collidable.h"

using namespace Sifteo;

class SolidObject {
    public:           
        BoundingBox () {
            return boundingBox;
        }
        
        virtual void draw(VideoBuffer *vid);
        void move();

    private:
        Int2 position;
        Int2 velocity;
        Int2 size;
        BoundingBox boundingBox;
        bool hasGravity;
};

#endif