#ifndef CAMERA_H
#define CAMERA_H

#include "rayheaders.h"
#include "rayrand.h"

class camera {
  public:
  double  aspect_ratio = 1.0;
  double  image_width = 100;
  int     max_depth = 10;
  int     samples_per_pixel = 10;


  void render(const hittable& world);

  private:
    int     image_height;
    point3  camera_center;
    vec3    pixel_delta_u;
    vec3    pixel_delta_v;
    point3  pixel00_loc;
    double  pixel_samples_scale;

    void initialize();

    color ray_color(const ray& r, int depth, const hittable& world) const;
};

#endif