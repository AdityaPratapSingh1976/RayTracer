#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"

color ray_color(const ray& r){
    return color(0,0,0);
}


int main() {
    auto aspect_ratio = 16.0/9.0;
    int image_width = 400;
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height; // ensure image height is at least 1

    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height); // image_width/image_height = aspect_ratio

    // aspect ratio is ideal ratio not actual ratio between image_width and image_height due to rounding to integer

    auto camera_center = point3(0,0,0);
    auto focal_length = 1.0;

    // camera center coordinate and focal length is distance between camera center and viewport

    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // viewport vector

    auto pixel_delta_u = viewport_u / image_width; // divide view port into pixels using image dimensions so that image fit in the viewport
    auto pixel_delta_v = viewport_v / image_height;
    
    // pixel delta vectors

    auto viewport_upper_left = camera_center - vec3(0,0,focal_length) - viewport_u/2 - viewport_v/2;

    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // upper left viewport corner and upper left pixel location

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) { // top to bottom
        std::clog << "\rScanlines remaining: " << (image_height - j)<<' '<< std::flush;
        for (int i = 0; i < image_width; i++) {// left to right
            auto pixel_center = pixel00_loc + i*pixel_delta_u + j*pixel_delta_v; // navigate through pixels using delta vectors
            auto ray_direction = pixel_center - camera_center; // vector substraction
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r); // trace ray r and tell me the color of the pixel

            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\nDone.\n";
}