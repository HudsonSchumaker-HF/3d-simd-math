#include "simd_math.h"
#include "test_common.h"

void test_mat4_mul_vec4(void) 
{
    /* Identity matrix */
    mat4 identity = mat4_identity();

    vec4 input = vec4_set(1.0f, 2.0f, 3.0f, 1.0f);
    vec4 result = mat4_mul_vec4(identity, input);

    ASSERT_NEAR(result.x, 1.0f);
    ASSERT_NEAR(result.y, 2.0f);
    ASSERT_NEAR(result.z, 3.0f);
    ASSERT_NEAR(result.w, 1.0f);

    /* General matrix */
    mat4 matrix = {{
        1.0f,  2.0f,  3.0f,  4.0f,
        5.0f,  6.0f,  7.0f,  8.0f,
        9.0f, 10.0f, 11.0f, 12.0f,
       13.0f, 14.0f, 15.0f, 16.0f
    }};

    input = vec4_set(1.0f, 2.0f, 3.0f, 4.0f);

    result = mat4_mul_vec4(matrix, input);

    /*
     * x = 1*1 + 2*2 + 3*3 + 4*4 = 30
     * y = 5*1 + 6*2 + 7*3 + 8*4 = 70
     * z = 9*1 + 10*2 + 11*3 + 12*4 = 110
     * w = 13*1 + 14*2 + 15*3 + 16*4 = 150
     */
    ASSERT_NEAR(result.x, 30.0f);
    ASSERT_NEAR(result.y, 70.0f);
    ASSERT_NEAR(result.z, 110.0f);
    ASSERT_NEAR(result.w, 150.0f);

    TEST_PASS("mat4_mul_vec4");
}

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

    test_mat4_mul_vec4();

    return 0;
}
