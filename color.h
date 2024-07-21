//
// Created by yashu on 24/06/24.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include "interval.h"
#include "vec3.h"

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color)
{
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    static const interval intensity (0.000, 0.999);
    int rbyte = int (255.999 * intensity.clamp(r));
    int gbyte = int (255.999 * intensity.clamp(g));
    int bbyte = int (255.999 * intensity.clamp(b));

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
#endif//RAYTRACER_COLOR_H
