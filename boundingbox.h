#ifndef _BOUNDINGBOX_H_
#define _BOUNDINGBOX_H_
#include <sifteo.h>

using namespace Sifteo;

class BoundingBox {
    public:        
        BoundingBox(Int2 pos, Int2 size): position(pos), size(size) {}
        
        void setPosition(Int2 p) { position = p; }
        Int2 getPosition() { return position; }
        Int2 getSize()     { return size; }
        
        bool intersects(BoundingBox b2) {
            return vectorLengthSquared(getIntersection(b2.getPosition(), b2.getSize())) > 0;
        }

        Int2 getIntersection(BoundingBox b) {
            return getIntersection(b.getPosition(), b.getSize());
        }
        Int2 getIntersection(Int2 p2, Int2 size2) {
            if (position.x > p2.x + size2.x || position.x + size.x < p2.x ||  // right or left of p2
                position.y + size.y < p2.y || position.y > p2.y + size2.y) {  // above or below p2
                return vec(0,0); // return no overlap
            }

            int xcol = 0;
            if (isInInterval(position.x, p2.x, size2.x)) {
                xcol = position.x - p2.x;
            }

            if (isInInterval(position.x + size.x, p2.x , size2.x)) {
                int tmp = position.x + size.x - p2.x;
                if (tmp > xcol)
                    xcol = tmp;
            }
            
            int ycol = 0;            
            if (isInInterval(position.y, p2.y, size2.y)) {
                ycol = position.y - p2.y;
            }
            
            if (isInInterval(position.y + size.y, p2.y , size2.y)) {
                int tmp = position.y + size.y - p2.y;
                if (tmp > ycol)
                    ycol = tmp;
            }

            return vec(xcol, ycol);
        }
        
                
        static int vectorLengthSquared(Int2 v) {
            return v.x*v.x + v.y*v.y;
        }

    private:
        Int2 position;
        Int2 size;

        int isInInterval(int x, int start, int intervalLength) {
            return (x >= start && x < start + intervalLength);
        }

};

#endif