
#include "vec4_sse41.h"

static inline __m128 vec4_load(vec4 v)
{
    return _mm_loadu_ps(&v.x);
}

static inline vec4 vec4_store(__m128 v)
{
    vec4 result;
    _mm_storeu_ps(&result.x, v);
    return result;
}

vec4 vec4_set(float x, float y, float z, float w)
{
    return vec4_store(_mm_set_ps(w, z, y, x));
}

vec4 vec4_add(vec4 a, vec4 b)
{
    return vec4_store(
        _mm_add_ps(vec4_load(a), vec4_load(b))
    );
}

vec4 vec4_sub(vec4 a, vec4 b)
{
    return vec4_store(
        _mm_sub_ps(vec4_load(a), vec4_load(b))
    );
}

vec4 vec4_scale(vec4 v, float scalar)
{
    return vec4_store(
        _mm_mul_ps(
            vec4_load(v),
            _mm_set1_ps(scalar)
        )
    );
}

float vec4_dot(vec4 a, vec4 b)
{
    __m128 result = _mm_dp_ps(
        vec4_load(a),
        vec4_load(b),
        0xF1
    );

    return _mm_cvtss_f32(result);
}

float vec4_length(vec4 v)
{
    return _mm_cvtss_f32(
        _mm_sqrt_ss(
            _mm_dp_ps(
                vec4_load(v),
                vec4_load(v),
                0xF1
            )
        )
    );
}

vec4 vec4_normalize(vec4 v)
{
    float length = vec4_length(v);

    if (length <= 1e-6f) {
        return vec4_set(0, 0, 0, 0);
    }

    return vec4_scale(v, 1.0f / length);
}
