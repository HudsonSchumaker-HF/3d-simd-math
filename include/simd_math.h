
#ifndef SIMD_MATH_H
#define SIMD_MATH_H

#include <stddef.h>

// ============================================
//  VECTORS
// ============================================ 
typedef struct vec4 {
    float x;
    float y;
    float z;
    float w;
} vec4;

vec4 vec4_set(float x, float y, float z, float w);
vec4 vec4_add(vec4 a, vec4 b);
vec4 vec4_sub(vec4 a, vec4 b);
vec4 vec4_scale(vec4 v, float scalar);
vec4 vec4_normalize(vec4 v);

float vec4_dot(vec4 a, vec4 b);
float vec4_length(vec4 v);

// ============================================
//  MATRICES
//
// Row-major storage.
// Matrix multiplication: C = A * B.
// ============================================

typedef struct mat4 {
    float m[16];
} mat4;

mat4 mat4_identity(void);
mat4 mat4_mul(mat4 a, mat4 b);
vec4 mat4_mul_vec4(mat4 m, vec4 v);
mat4 mat4_transpose(mat4 m);

#endif /* SIMD_MATH_H */
