#ifndef _SOLIDOBJECT_H_
#define _SOLIDOBJECT_H_

class Vector2D {
    public:
        Vector2D(int x, int y): x(x), y(y) {};
        int x;
        int y;
};

class SolidObject{
    public:
        SolidObject() : position(0,0), velocity(0,0), width(0), height(0), weight(0) 
        { };
    private:
        Vector2D position;
        Vector2D velocity;
        int width;
        int height;        
        int weight;
};

#endif