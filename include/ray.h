#ifndef RAY_H
#define RAY_H

#include "vec3.h"
#include <cassert>

class ray{
    private:
    point3 orig; // A
    vec3 dir; // b
    public:
        ray(){}
        ray(const point3& origin, const vec3& direction);
        const point3& origin() const;
        const vec3& direction() const;
        point3 at(const double t) const;
};
#endif