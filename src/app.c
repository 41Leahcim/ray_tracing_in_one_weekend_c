#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "color.hpp"
#include "ray.h"

bool hit_sphere(const Point3 center, double radius, const Ray ray){
    Vec3 distance_origin_center = vec3_subtract(ray.origin, center);
    double a = vec3_dot(ray.direction, ray.direction);
    double b = 2.0 * vec3_dot(distance_origin_center, ray.direction);
    double c = vec3_dot(distance_origin_center, distance_origin_center) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    return discriminant > 0;
}

Color ray_color(const Ray ray){
    if(hit_sphere((Point3){{0.0, 0.0, -1.0}}, 0.5, ray)){
        return (Color){{1.0, 0.0, 0.0}};
    }
    const Vec3 unit_direction = vec3_unit_vector(ray.direction);
    const double time = 0.5 * (unit_direction.elements[1] + 1.0);
    return vec3_add(
        multiply_double_vec3((1.0 - time), (Vec3){{1.0, 1.0, 1.0}}),
        multiply_double_vec3(time, (Vec3){{0.5, 0.7, 1.0}})
    );
}

int main(){
    // Start measuring time
    clock_t start = clock();

    // Image properties
    const double ASPECT_RATIO = 16.0 / 9.0;
    const int IMAGE_WIDTH = 4096;
    const int IMAGE_HEIGHT = (int)(IMAGE_WIDTH / ASPECT_RATIO);

    // Camera
    const double VIEWPORT_HEIGHT = 2.0;
    const double VIEWPORT_WIDTH = ASPECT_RATIO * VIEWPORT_HEIGHT;
    const double FOCAL_LENGTH = 1.0;

    Point3 origin = {{0.0, 0.0, 0.0}};
    Vec3 horizontal = {{VIEWPORT_WIDTH, 0.0, 0.0}};
    Vec3 vertical = {{0.0, VIEWPORT_HEIGHT, 0.0}};
    Point3 lower_left_corner = vec3_subtract(
        vec3_subtract(
            vec3_subtract(
                origin,
                (Vec3){{0.0, 0.0, FOCAL_LENGTH}}
            ),
            vec3_divide_double(vertical, 2.0)
        ),
        vec3_divide_double(horizontal, 2.0)
    );

    // Rendering
    printf("P3\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);

    for(int y = IMAGE_HEIGHT - 1;y >= 0;y--){
        fprintf(stderr, "\rscanlines remaining: %-4d", y);
        fflush(stderr);
        for(int x = 0;x < IMAGE_WIDTH;x++){
            double u = (double)x / (IMAGE_WIDTH - 1);
            double v = (double)y / (IMAGE_HEIGHT - 1);
            Ray ray = {
                .origin=origin,
                .direction = vec3_add(
                    lower_left_corner,
                    vec3_add(
                        vec3_multiply_double(horizontal, u),
                        vec3_subtract(
                            vec3_multiply_double(vertical, v),
                            origin
                        )
                    )
                )
            };
            Color pixel_color = ray_color(ray);
            color_write(stdout, pixel_color);
        }
    }
    fprintf(stderr, "\nDone\n");

    // Print time
    fprintf(stderr, "%lf\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}
