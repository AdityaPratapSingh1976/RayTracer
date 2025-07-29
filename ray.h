#ifndef RAY_H
#define RAY_H

#include "vec3.h"
#include <cassert>

class ray{ // r(t) = A + tb
    private:
    point3 orig; // A
    vec3 dir; // b
    public:
        ray(){}
        ray(const point3& origin, const vec3& direction): orig(origin), dir(direction){}
        const point3& origin() const {return orig;}
        const vec3& direction() const {return dir;}
        point3 at double(t) const{
            assert(t >= 0);
            return orig + t*dir;
        }
};
#endif