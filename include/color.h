#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include "interval.h"
class vec3;
#include <iostream>
using color = vec3;
double inline linear_to_gamma(double linear_component){
    return sqrt(linear_component);
}
void inline write_color(std::ostream &out, const color &pixel_color){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();
    static const interval intensity(0.000, 0.999);
    int rbyte = int(256 * intensity.clamp(linear_to_gamma(r)));
    int gbyte = int(256 * intensity.clamp(linear_to_gamma(g)));
    int bbyte = int(256 * intensity.clamp(linear_to_gamma(b)));


    out << rbyte << " " << gbyte << " " << bbyte << "\n";
};

#endif