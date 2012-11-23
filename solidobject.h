#ifndef _SOLIDOBJECT_H_
#define _SOLIDOBJECT_H_
#include <sifteo.h>

using namespace Sifteo;

class SolidObject{
    public:
        SolidObject() : position(vec(0,0)), velocity(vec(0,0)), affectedByGravity(true), height(0), width(0) 
        { };
        SolidObject(Int2 pos, Int2 vel, int w, int h, bool gravity):
            position(pos), velocity(vel), affectedByGravity(gravity), height(h), width(w)   {};
    private:
        Int2 position;
        Int2 velocity;
        bool affectedByGravity;
        int height;        
        int width;
};

#endif