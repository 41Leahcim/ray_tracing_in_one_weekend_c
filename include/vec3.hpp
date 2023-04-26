#pragma once

#include <stdio.h>
#include <stddef.h>

typedef struct{
    double elements[3];
} Vec3;

Vec3 negate(const Vec3 vector);

Vec3 vec3_add(const Vec3 vector, const Vec3 vector2);
Vec3 vec3_subtract(const Vec3 vector, const Vec3 vector2);
Vec3 vec3_multiply(const Vec3 vector, const Vec3 vector2);

Vec3 vec3_multiply_double(const Vec3 vector, const double times);
Vec3 vec3_divide_double(const Vec3 vector, const double times);

double vec3_dot(const Vec3 vector, const Vec3 vector2);
Vec3 vec3_cross(const Vec3 vector, const Vec3 vecto2);

Vec3* vec3_add_assign(Vec3 *vector, const Vec3 vector2);
Vec3* vec3_multiply_assign(Vec3 *vector, const Vec3 vector2);
Vec3* vec3_divide_assign(Vec3 *vector, const Vec3 vector2);

double vec3_length(const Vec3 vector);
double vec3_length_squared(const Vec3 vector);
Vec3 vec3_unit_vector(const Vec3 vector);

typedef Vec3 Point3;
typedef Vec3 Color;

void vec3_print(FILE *output, Vec3 vector);
Vec3 multiply_double_vec3(const double times, const Vec3 vector);
