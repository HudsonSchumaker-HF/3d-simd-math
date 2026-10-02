
#include "mat4_sse41.h"

mat4 mat4_identity(void)
{
    mat4 result = {{
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    }};

    return result;
}

mat4 mat4_mul(mat4 a, mat4 b)
{
    mat4 result;

    const float* A = a.m;
    const float* B = b.m;
    float* C = result.m;

    const __m128 B0 = _mm_loadu_ps(&B[0]);
    const __m128 B1 = _mm_loadu_ps(&B[4]);
    const __m128 B2 = _mm_loadu_ps(&B[8]);
    const __m128 B3 = _mm_loadu_ps(&B[12]);

    for (int row = 0; row < 4; ++row) {
        const __m128 ar = _mm_loadu_ps(&A[row * 4]);

        const __m128 a0 = _mm_shuffle_ps(
            ar, ar, _MM_SHUFFLE(0, 0, 0, 0)
        );

        const __m128 a1 = _mm_shuffle_ps(
            ar, ar, _MM_SHUFFLE(1, 1, 1, 1)
        );

        const __m128 a2 = _mm_shuffle_ps(
            ar, ar, _MM_SHUFFLE(2, 2, 2, 2)
        );

        const __m128 a3 = _mm_shuffle_ps(
            ar, ar, _MM_SHUFFLE(3, 3, 3, 3)
        );

        __m128 r = _mm_mul_ps(a0, B0);

        r = _mm_add_ps(r, _mm_mul_ps(a1, B1));
        r = _mm_add_ps(r, _mm_mul_ps(a2, B2));
        r = _mm_add_ps(r, _mm_mul_ps(a3, B3));

        _mm_storeu_ps(&C[row * 4], r);
    }

    return result;
}

mat4 mat4_transpose(mat4 m)
{
    mat4 result;

    __m128 row0 = _mm_loadu_ps(&m.m[0]);
    __m128 row1 = _mm_loadu_ps(&m.m[4]);
    __m128 row2 = _mm_loadu_ps(&m.m[8]);
    __m128 row3 = _mm_loadu_ps(&m.m[12]);

    _MM_TRANSPOSE4_PS(row0, row1, row2, row3);

    _mm_storeu_ps(&result.m[0], row0);
    _mm_storeu_ps(&result.m[4], row1);
    _mm_storeu_ps(&result.m[8], row2);
    _mm_storeu_ps(&result.m[12], row3);

    return result;
}
