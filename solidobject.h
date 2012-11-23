#ifndef _SOLIDOBJECT_H_
#define _SOLIDOBJECT_H_
#include <sifteo.h>

using namespace Sifteo;

class SolidObject{
    public:
        SolidObject() : 
            position(vec(0,0)), velocity(vec(0,0)), affectedByGravity(true), width(0), height(0) { 
                currentPosition = position; 
        };
        
        SolidObject(Int2 pos, Int2 vel, bool gravity, int w, int h):
            position(pos), velocity(vel), affectedByGravity(gravity), width(w), height(h) { 
                currentPosition = position; 
        };
        
        int getX() { return currentPosition.x; }
        int getY() { return currentPosition.y; }
        int getWidth() { return width; }
        int getHeight() { return height; }
        bool isAffectedByGravity() { return affectedByGravity; }
        
        void move() {
            if (currentPosition.y < 1)
                movingUp = false;
                
            if (currentPosition.y > position.y)
                movingUp = true;
                
            if (movingUp) {
                currentPosition = vec(currentPosition.x, currentPosition.y - 1);
            } else
                currentPosition = vec(currentPosition.x, currentPosition.y + 1);
                
            LOG("%d vs %d\n", currentPosition.y, position.y);
        }
        
    private:
        Int2 position;
        Int2 velocity;
        bool affectedByGravity;
        int width;
        int height;   
        
        // tmp stuff
        Int2 currentPosition;
        bool movingUp = true;
};

#endif