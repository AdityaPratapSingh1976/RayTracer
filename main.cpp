
#include <memory>
#include "include/rayheaders.h"
#include "include/hittable.h"
#include "include/hittable_list.h"
#include "include/sphere.h"


int main() {

    hittable_list world;

    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5, color(0.8, 0.2, 0.8)));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100, color(0.5, 0.5, 0.5))); //ground
    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.max_depth = 10;
    cam.samples_per_pixel = 100;
    cam.render(world); 
}