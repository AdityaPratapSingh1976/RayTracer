#include "../include/camera.h"

void camera::render(const hittable &world){
    this->initialize(); 
    auto sample_square = [&]()->vec3{
        return vec3(random_double() - 0.5, random_double() - 0.5,0);
    };
    auto get_ray = [&](int i, int j)->ray{
        auto offset = sample_square();
        auto pixel_center = pixel00_loc +   (i + offset.x())*pixel_delta_u 
                                        +   (j + offset.y())*pixel_delta_v; // navigate through pixels using delta vectors
        auto ray_direction = pixel_center - camera_center; // vector substraction
        return ray(camera_center, ray_direction);
    };
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) { // top to bottom
        std::clog << "\rScanlines remaining: " << (image_height - j)<<' '<< std::flush;
        for (int i = 0; i < image_width; i++) {// left to right
            color pixel_color(0,0,0);
            for(int sample = 0; sample < samples_per_pixel; sample++){
                ray r = get_ray(i,j);
                pixel_color += ray_color(r, max_depth, world);
            }
            write_color(std::cout, pixel_color * pixel_samples_scale);
        }
    }
    std::clog << "\nDone.\n";
}


// private methods
void camera::initialize(){
    image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;
    camera_center = point3(0,0,0);

    pixel_samples_scale = 1.0 / samples_per_pixel;
    
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height); // image_width/image_height = aspect_ratio
    auto focal_length = 1.0;
    // aspect ratio is ideal ratio not actual ratio between image_width and image_height due to rounding to integer

    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);
    // viewport vectors

    pixel_delta_u = viewport_u / image_width; // divide view port into pixels using image dimensions so that image fit in the viewport
    pixel_delta_v = viewport_v / image_height;
    
    // pixel delta vectors

    auto viewport_upper_left = camera_center - vec3(0,0,focal_length) - viewport_u/2 - viewport_v/2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    // upper left viewport corner and upper left pixel location 
}


color camera::ray_color(const ray& r,int depth, const hittable& world) const {
    hit_record rec;

    if(depth <= 0)return color(0,0,0);

    if (world.hit(r, interval(0.001, infinity), rec)) {
        return rec.attenuation * ray_color(ray(rec.p, rec.scatter), depth - 1, world);
    }

    vec3 unit_dir = unit_vector(r.direction());
    auto a = 0.5 * (unit_dir.y() + 1.0);
    return color(1.0, 1.0, 1.0) * (1.0 - a) + color(0.5, 0.7, 1.0)*a;
}

    