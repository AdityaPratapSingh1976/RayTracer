# RayTracer

A simple C++ ray tracer that renders spheres with basic shading, inspired by *Ray Tracing in One Weekend*.

---

This RayTracer can:

- Cast rays into a 3D scene with spheres
- Compute sphere intersections and normals
- Shade with a simple diffuse / background gradient
- Output images in PPM format
- antialising
---

## Features & To‑Do

### Completed
- Sphere-ray intersection
- Surface normal calculation
- Basic ray-color shading based on normals
- PPM image output
- Anti-aliasing (supersampling)
- Diffuse material added
### Planned (To‑Do)
- [ ] Material to add : Metallic and Dielectrics
- [ ] Reflection and refraction (recursive ray tracing)  
- [ ] Multiple sphere geometries (ground plane, boxes, triangles)
- [ ] Depth of field (camera aperture / focal plane)
- [ ] Multi-threaded rendering for parallel speed‑up
- [ ] Reflection and refraction (recursive ray tracing)
- [ ] Output image formats beyond PPM (PNG)
- [ ] Unit tests for vector math, ray-geometry intersection, utilities

---

## Getting Started

### Prerequisites
- C++17-compatible compiler (e.g. GCC, Clang)
- CMake ≥ 3.10

### Build and Run

mkdir build

cd build

cmake ..

cmake --build .

# Render output:
./RayTracer > output.ppm

### Adding objects 
```
int main() {

    hittable_list world;

    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5, color(0.8, 0.2, 0.8)));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100, color(0.5, 0.5, 0.5)));
    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.max_depth = 10;
    cam.samples_per_pixel = 100;
    cam.render(world); 
}
```
use world.add to add sphere 
and camera public members to tweek image

