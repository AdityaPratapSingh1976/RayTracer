#ifndef RAYRAND_H
#define RAYRAND_H

#include <cstdlib>

inline double random_double(){ //[0,1)
    return rand()/(RAND_MAX + 1.0);
}

inline double random_double(double min, double max){ //[min,max)
    return min + (max-min)*random_double();
}
#endif