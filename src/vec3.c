#include "vec3.hpp"

#include <math.h>

Vec3 negate(const Vec3 vector){
    return (Vec3){{
        vector.elements[0],
        vector.elements[1],
        vector.elements[2]
    }};
}

Vec3 vec3_add(const Vec3 vector, const Vec3 vector2){
    return (Vec3){{
        vector.elements[0] + vector2.elements[0],
        vector.elements[1] + vector2.elements[1],
        vector.elements[2] + vector2.elements[2]
    }};
}

Vec3 vec3_subtract(const Vec3 vector, const Vec3 vector2){
    return (Vec3){{
        vector.elements[0] - vector2.elements[0],
        vector.elements[1] - vector2.elements[1],
        vector.elements[2] - vector2.elements[2]
    }};
}
Vec3 vec3_multiply(const Vec3 vector, const Vec3 vector2){
    return (Vec3){{
        vector.elements[0] * vector2.elements[0],
        vector.elements[1] * vector2.elements[1],
        vector.elements[2] * vector2.elements[2]
    }};
}

Vec3 vec3_multiply_double(const Vec3 vector, const double times){
    return (Vec3){{
        vector.elements[0] * times,
        vector.elements[1] * times,
        vector.elements[2] * times
    }};
}

Vec3 vec3_divide_double(const Vec3 vector, const double times){
    return (Vec3){{
        vector.elements[0] / times,
        vector.elements[1] / times,
        vector.elements[2] / times
    }};
}

double vec3_dot(const Vec3 vector, const Vec3 vector2){
    return 
        vector.elements[0] * vector2.elements[0] +
        vector.elements[1] * vector2.elements[1] +
        vector.elements[2] * vector2.elements[2];
}

Vec3 vec3_cross(const Vec3 vector, const Vec3 vector2){
    return (Vec3){{
        vector.elements[1] * vector2.elements[2] - vector.elements[2] * vector2.elements[1],
        vector.elements[2] * vector2.elements[0] - vector.elements[0] * vector2.elements[2],
        vector.elements[0] * vector2.elements[1] - vector.elements[1] * vector2.elements[0]
    }};
}

Vec3* vec3_add_assign(Vec3 *vector, const Vec3 vector2){
    vector->elements[0] += vector2.elements[0];
    vector->elements[1] += vector2.elements[1];
    vector->elements[2] += vector2.elements[2];
    return vector;
}

Vec3* vec3_multiply_assign(Vec3 *vector, const Vec3 vector2){
    vector->elements[0] *= vector2.elements[0];
    vector->elements[1] *= vector2.elements[1];
    vector->elements[2] *= vector2.elements[2];
    return vector;
}

Vec3* vec3_divide_assign(Vec3 *vector, const Vec3 vector2){
    vector->elements[0] /= vector2.elements[0];
    vector->elements[1] /= vector2.elements[1];
    vector->elements[2] /= vector2.elements[2];
    return vector;
}

double vec3_length(const Vec3 vector){
    return sqrt(vec3_length_squared(vector));
}

double vec3_length_squared(const Vec3 vector){
    return vector.elements[0] * vector.elements[0] +
        vector.elements[1] * vector.elements[1] +
        vector.elements[2] * vector.elements[2];
}

Vec3 vec3_unit_vector(const Vec3 vector){
    return vec3_divide_double(vector, vec3_length(vector));
}

Vec3 multiply_double_vec3(const double times, const Vec3 vector){
    return vec3_multiply_double(vector, times);
}
