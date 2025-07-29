#ifndef HITTABLE_H
#define HITTABLE_H

#include "rayheaders.h"
class hit_record { // record hit info
  public:
    point3 p;
    vec3 normal;
    double t;
    bool front_face;
    color attenuation;
    vec3 scatter;
    void set_face_normal(const ray&r, const vec3& out_norm){
        front_face = dot(r.direction(), out_norm) < 0;
        normal = front_face ? out_norm : -out_norm;
    }
};

class hittable {
  public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;

};

#endif