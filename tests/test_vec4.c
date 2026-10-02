
#include "simd_math.h"
#include "test_common.h"

int main(void)
{
    vec4 a = vec4_set(1, 2, 3, 4);
    vec4 b = vec4_set(5, 6, 7, 8);

    vec4 sum = vec4_add(a, b);

    ASSERT_NEAR(sum.x, 6);
    ASSERT_NEAR(sum.y, 8);
    ASSERT_NEAR(sum.z, 10);
    ASSERT_NEAR(sum.w, 12);

    vec4 difference = vec4_sub(b, a);

    ASSERT_NEAR(difference.x, 4);
    ASSERT_NEAR(difference.y, 4);
    ASSERT_NEAR(difference.z, 4);
    ASSERT_NEAR(difference.w, 4);

    float dot = vec4_dot(a, b);

    ASSERT_NEAR(dot, 70);

    vec4 scaled = vec4_scale(a, 2);

    ASSERT_NEAR(scaled.x, 2);
    ASSERT_NEAR(scaled.y, 4);
    ASSERT_NEAR(scaled.z, 6);
    ASSERT_NEAR(scaled.w, 8);

    vec4 normalized = vec4_normalize(a);

    ASSERT_NEAR(vec4_length(normalized), 1.0f);

    TEST_PASS("vec4");

    return 0;
}
