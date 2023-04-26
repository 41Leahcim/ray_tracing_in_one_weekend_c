#include "ray.h"

Point3 at(Ray ray, double time){
    return vec3_add(ray.origin, multiply_double_vec3(time, ray.direction));
}
