
#include "simd_math.h"
#include "test_common.h"

int main(void)
{
    mat4 identity = mat4_identity();

    for (int i = 0; i < 16; ++i) {
        float expected = (i % 5 == 0) ? 1.0f : 0.0f;
        ASSERT_NEAR(identity.m[i], expected);
    }

    mat4 a = {{
        1,  2,  3,  4,
        5,  6,  7,  8,
        9, 10, 11, 12,
        13,14, 15, 16
    }};

    mat4 result = mat4_mul(a, identity);

    for (int i = 0; i < 16; ++i) {
        ASSERT_NEAR(result.m[i], a.m[i]);
    }

    mat4 transposed = mat4_transpose(a);

    ASSERT_NEAR(transposed.m[0], 1);
    ASSERT_NEAR(transposed.m[1], 5);
    ASSERT_NEAR(transposed.m[2], 9);
    ASSERT_NEAR(transposed.m[3], 13);

    ASSERT_NEAR(transposed.m[4], 2);
    ASSERT_NEAR(transposed.m[5], 6);

    mat4 double_transpose = mat4_transpose(transposed);

    for (int i = 0; i < 16; ++i) {
        ASSERT_NEAR(double_transpose.m[i], a.m[i]);
    }

    TEST_PASS("mat4");

    return 0;
}
