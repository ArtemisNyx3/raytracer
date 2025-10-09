#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

using color = vec3;

// buffer, color vector
void write_color(std::ostream &out, const color &pixel_color)
{
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // vec3 is in double[0,1]
    // changing it to int[0,255] for color
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // Write the pixel
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif