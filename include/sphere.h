#ifndef SPHERE_H
#define SPHERE_H

#include "rayheaders.h"
#include "hittable.h"

class sphere : public hittable {
    private:
        point3 center;
        double radius;
        color albedo;
    public:
        sphere(const point3& center, double radius, const color& albedo) : center(center), radius(std::fmax(0,radius)), albedo(albedo) {}

        bool hit(const ray& r, interval t, hit_record& rec) const override {
            vec3 oc = center - r.origin();
            auto a = r.direction().length_squared();
            auto h = dot(r.direction(), oc); // simplification: b = -2*h to remove multiply by 2.0
            //multiplication costly!!
            auto c = oc.length_squared() - radius*radius;

            auto discriminant = h*h - a*c;
            if (discriminant < 0)
                return false;

            auto sqrtd = std::sqrt(discriminant);


            auto root = (h - sqrtd) / a;
            if(!t.surrounds(root)){
                root = (h + sqrtd) / a;
                if(!t.surrounds(root))
                    return false;
            }

            rec.t = root;
            rec.p = r.at(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.attenuation = albedo;
            rec.scatter = rec.normal + random_unit_vector();
            return true;    
        }

};

#endif