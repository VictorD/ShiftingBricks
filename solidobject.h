#ifndef _SOLIDOBJECT_H_
#define _SOLIDOBJECT_H_
#include <sifteo.h>

using namespace Sifteo;

class SolidObject{
    public:
        SolidObject() : 
            position(vec(0,0)), velocity(vec(0,0)), hasGravity(true), width(0), height(0) { 
        };
        
        SolidObject(Int2 pos, Int2 vel, bool gravity, int w, int h):
            position(pos), velocity(vel), hasGravity(gravity), width(w), height(h) { 
        };
        
        int getX() { return position.x; }
        int getY() { return position.y; }
        Int2 getPosition() { return position; }
        int getWidth() { return width; }
        int getHeight() { return height; }
        bool isAffectedByGravity() { return hasGravity; }
        void setFalling(bool falling) { hasGravity = falling; }
        
        void move(Int2 vel) {
            velocity = vec(velocity.x + vel.x , velocity.y + vel.y);
        }
        
        void move() {
            int gravity =  hasGravity;
            
            position = vec(position.x + velocity.x, position.y + velocity.y + gravity);
            
            if (vectorLengthSquared(velocity) > 0)
                LOG("new position: %d, %d\n", position.x, position.y);
        }
        
        void collidesWith(SolidObject *s2) {
            Int2 p1 = position;
            Int2 p2 = s2->getPosition();
            Int2 size1 = vec(width, height);
            Int2 size2 = vec(s2->getWidth(), s2->getHeight());

            Int2 collisionVector = getRectCollisionVector(p1, size1, p2, size2);
            if (vectorLengthSquared(collisionVector) > 0) {
                position = vec(position.x, position.y - 1);
                LOG("collision moved: %d, %d\n", collisionVector.x, collisionVector.y);
                hasGravity = false;
            }
        }
        
        bool testCollision(SolidObject *s2) {
            Int2 p1 = position;
            Int2 p2 = s2->getPosition();
            Int2 size1 = vec(width, height);
            Int2 size2 = vec(s2->getWidth(), s2->getHeight());
            
            Int2 collisionVector = getRectCollisionVector(p1, size1, p2, size2);
            return vectorLengthSquared(collisionVector) > 0;
        }
        
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
        
        int vectorLengthSquared(Int2 v) {
            return v.x*v.x + v.y*v.y;
        }
        
        int isInInterval(int x, int start, int intervalLength) {
            return (x >= start && x < start + intervalLength);
        }
        
    private:
        Int2 position;
        Int2 velocity;
        bool hasGravity;
        int width;
        int height;   
};

#endif