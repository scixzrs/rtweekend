#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "raytracer.h"
#include "sphere.h"

/*double hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = center - r.origin();
    auto a = r.direction().length_squared();
    auto h = dot(r.direction(), oc);
    auto c = oc.length_squared() - radius * radius;
    auto discriminant = h * h - a * c;

    if (discriminant < 0){
        return -1.0;
    } else {
        return (h - sqrt(discriminant)) / a;
    }
}*/

int main() {
    hittable_list world;

    auto R = std::cos(pi/4);

    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = make_shared<lambertian>(color(0.1,0.2,0.5));
    auto material_left = make_shared<dielectric>(1.50);
    auto material_bubble = make_shared<dielectric>(1.00/1.50);
    auto material_right = make_shared<metal>(color(0.8, 0.4, 0.7),0.8);

    world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3(0.0, 0.0, -1.2), 0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, material_left));
    world.add(make_shared<sphere>(point3(-1.0,0.0,-1.0),0.4,material_bubble));
    world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5, material_right));

    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;

    cam.vfov = 20;
    cam.lookfrom = point3 (-2,2,1);
    cam.lookat = point3 (0,0,-1);
    cam.vup = vec3(0,1,0);

    cam.render(world);
}
