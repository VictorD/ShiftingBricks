#ifndef _SOLIDOBJECT_H_
#define _SOLIDOBJECT_H_
#include <sifteo.h>

using namespace Sifteo;

class SolidObject {
    public:
        SolidObject() : 
            position(vec(0,0)), velocity(vec(0,0)), hasGravity(true), width(0), height(0) { 
        };
        
        SolidObject(Int2 pos, Int2 vel, bool gravity, int w, int h):
            position(pos), velocity(vel), hasGravity(gravity), width(w), height(h) { 
        };
        
        Int2 getPosition() { return position; }
        Int2 getSize() { return vec(width, height); }
        int getX() { return position.x; }
        int getY() { return position.y; }
        int getWidth() { return width; }
        int getHeight() { return height; }
        
        bool isAffectedByGravity() { return hasGravity; }
        void setFalling(bool falling) { hasGravity = falling; }
        
        void draw(VideoBuffer *vid);        
        void collidesWith(SolidObject *s2);
        bool testCollision(SolidObject *s2);
        
        void move();
        void addVelocity(Int2 vel) {
            velocity = vec(velocity.x + vel.x , velocity.y + vel.y);
        }
        
    private:
        Int2 position;
        Int2 velocity;
        bool hasGravity;
        int width;
        int height;   
        
        Int2 getRectCollisionVector(Int2 p1, Int2 size1, Int2 p2, Int2 size2) {

            if (p1.x > p2.x + size2.x || p1.x + size1.x < p2.x ||  // p1 right or left of p2
                p1.y + size1.y < p2.y || p1.y > p2.y + size2.y) {  // P1 above or below p2
                return vec(0,0); // return no overlap
            }

            int xcol = 0;
            if (isInInterval(p1.x, p2.x, size2.x)) {
                xcol = p1.x - p2.x;
            }

            if (isInInterval(p1.x + size1.x, p2.x , size2.x)) {
                int tmp = p1.x + size1.x - p2.x;
                if (tmp > xcol)
                    xcol = tmp;
            }
            
            int ycol = 0;            
            if (isInInterval(p1.y, p2.y, size2.y)) {
                ycol = p1.y - p2.y;
            }
            
            if (isInInterval(p1.y + size1.y, p2.y , size2.y)) {
                int tmp = p1.y + size1.y - p2.y;
                if (tmp > ycol)
                    ycol = tmp;
            }

            return vec(xcol, ycol);
        }
         
        int isInInterval(int x, int start, int intervalLength) {
            return (x >= start && x < start + intervalLength);
        }
        
        int vectorLengthSquared(Int2 v) {
            return v.x*v.x + v.y*v.y;
        }
};

#endif