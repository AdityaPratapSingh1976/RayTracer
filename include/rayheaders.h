#ifndef RAYHEADERS_H
#define RAYHEADERS_H
#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

using std::make_shared;
using std::shared_ptr;

const double pi = 3.1415926535897932385;

inline double degtorad(double deg){
    return deg * pi / 180.0;
}

//core types
#include "vec3.h"
#include "interval.h"
#include "color.h"
#include "ray.h"
#include "rayrand.h"

//dependent types
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"

#endif