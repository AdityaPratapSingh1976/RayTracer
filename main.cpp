#include <iostream>
#include "vec3.h"
#include "color.h"

int main() {
    auto aspect_ratio = 16.0/9.0;
    int image_width = 400;
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height; // ensure image height is at least 1

    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height); // image_width/image_height = aspect_ratio

    // aspect ratio is ideal ratio not actual ratio between image_width and image_height due to rounding to integer

    const int width = 256;
    const int height = 256;

    std::cout << "P3\n" << width << " " << height << "\n255\n";

    for (int j = height - 1; j >= 0; j--) {
        std::clog << "\rScanlines remaining: " << j << '\n';
        for (int i = 0; i < width; i++) {
            auto pixelcolor = color(double(i)/(width - 1), double(j)/(height - 1), 0.25);
            write_color(std::cout, pixelcolor);
        }
    }
    std::clog << "\nDone.\n";
}