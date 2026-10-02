#include "simd_math.h"
#include "test_common.h"

int main(void)
{
    mat4 identity = mat4_identity();

    /* Identity matrix */
    for (int i = 0; i < 16; ++i) {
        const float expected = (i % 5 == 0) ? 1.0f : 0.0f;
        ASSERT_NEAR(identity.m[i], expected);
    }

    /* Matrix multiplication */
    mat4 matrix_a = {{
        1,  2,  3,  4,
        5,  6,  7,  8,
        9, 10, 11, 12,
        13,14, 15, 16
    }};

    mat4 result = mat4_mul(matrix_a, identity);

    for (int i = 0; i < 16; ++i) {
        ASSERT_NEAR(result.m[i], matrix_a.m[i]);
    }

    /* Transpose */
    mat4 transposed = mat4_transpose(matrix_a);

    ASSERT_NEAR(transposed.m[0],  1);
    ASSERT_NEAR(transposed.m[1],  5);
    ASSERT_NEAR(transposed.m[2],  9);
    ASSERT_NEAR(transposed.m[3], 13);

    ASSERT_NEAR(transposed.m[4], 2);
    ASSERT_NEAR(transposed.m[5], 6);

    /* Transpose twice == original */
    mat4 double_transpose = mat4_transpose(transposed);

    for (int i = 0; i < 16; ++i) {
        ASSERT_NEAR(double_transpose.m[i], matrix_a.m[i]);
    }

    TEST_PASS("mat4");

    return 0;
}
