#ifndef _SOLIDOBJECT_H_
#define _SOLIDOBJECT_H_
#include <sifteo.h>
#include "boundingbox.h"

using namespace Sifteo;

class SolidObject {
    public:
        SolidObject(): boundingBox(position, size) {
            position = vec(0,0);
            velocity = vec(0,0);
            size = vec(0,0);
            gravity = false;
        }
        
        SolidObject (Int2 position, Int2 velocity, bool hasGravity, int width, int height) :
            position(position), velocity(velocity), boundingBox(position, size),  gravity(hasGravity) {
            size.x = width;
            size.y = height;
        }

        Int2 getPosition() { return position; }
        Int2 getSize() { return size; }
        
        bool hasGravity() { return gravity; }
        
        virtual bool isStatic() { return true; }
        virtual void draw(VideoBuffer *vid);
        void move();
        
        BoundingBox getBoundingBox() { return boundingBox; }
        bool collidesWith(SolidObject *s2);
        bool collidesWith(BoundingBox b2);
        void handleCollision(SolidObject *s2);

    private:
        Int2 position;
        Int2 velocity;
        Int2 size;
        BoundingBox boundingBox;
        bool gravity;
};

#endif