#ifndef _SOLIDOBJECT_H_
#define _SOLIDOBJECT_H_
#include <sifteo.h>

using namespace Sifteo;

class SolidObject{
    public:
        SolidObject() : position(vec(0,0)), velocity(vec(0,0)), width(0), height(0), weight(0) 
        { };
    private:
        Int2 position;
        Int2 velocity;
        int width;
        int height;        
        int weight;
};

#endif