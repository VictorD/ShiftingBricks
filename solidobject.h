#ifndef _SOLIDOBJECT_H_
#define _SOLIDOBJECT_H_
#include <sifteo.h>

using namespace Sifteo;

class SolidObject{
    public:
        SolidObject() : position(vec(0,0)), velocity(vec(0,0)), affectedByGravity(true), width(0), height(0)
        { };
        SolidObject(Int2 pos, Int2 vel, int w, int h, bool gravity):
            position(pos), velocity(vel), affectedByGravity(gravity), width(w), height(h) {};
        int getX() { return position.x; }
        int getY() { return position.y; }
        int getHeight() { return height; }
        int getWidth() { return width; }
    private:
        Int2 position;
        Int2 velocity;
        bool affectedByGravity;
        int width;
        int height;        
};

#endif