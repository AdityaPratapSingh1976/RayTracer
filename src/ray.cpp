#include "ray.h"
#include "vec3.h"


ray::ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

const point3& ray::origin() const {
    return orig;
}
const vec3& ray::direction() const{
    return dir;
};
point3 ray::at(const double t) const{
    assert(t >= 0);
    return orig + t * dir;
};