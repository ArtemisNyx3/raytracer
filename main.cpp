#include "raytracer.h"

#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"

#include <chrono>

int main()
{
    auto start_time = std::chrono::high_resolution_clock::now();
    // Image

    // World
    hittable_list world;
    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    // Camera
    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 800;
    cam.samples_per_pixel = 100;

    cam.render(world);

    // Render

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::clog << "Render time: " << duration << " ms\n";
}