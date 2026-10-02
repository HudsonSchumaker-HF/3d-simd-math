#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include <stdio.h>
#include <math.h>

#define TEST_EPSILON 1e-5f

#define ASSERT_TRUE(condition)                                      \
    do {                                                            \
        if (!(condition)) {                                         \
            printf("FAIL: %s:%d: %s\n",                             \
                   __FILE__, __LINE__, #condition);                \
            return 1;                                               \
        }                                                           \
    } while (0)

#define ASSERT_NEAR(actual, expected)                               \
    do {                                                            \
        const float actual_value = (actual);                       \
        const float expected_value = (expected);                   \
                                                                    \
        if (fabsf(actual_value - expected_value) > TEST_EPSILON) {  \
            printf("FAIL: %s:%d: expected %.6f, got %.6f\n",       \
                   __FILE__, __LINE__,                              \
                   expected_value, actual_value);                   \
            return 1;                                               \
        }                                                           \
    } while (0)

#define TEST_PASS(name)                                             \
    printf("[PASS] %s\n", (name))

#endif
