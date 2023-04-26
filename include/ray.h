#pragma once

#include "vec3.hpp"

typedef struct{
    Point3 origin;
    Vec3 direction;
} Ray;

Point3 at(Ray ray, double time);
