#include "libmath.h"

float sqrt(float x) {
    union {float f; long i;} u = { x };
    const float threehalfs = 1.5f;

    u.i = 0x5f3759df - (u.i >> 1); // wtf ?

    float x2 = x * 0.5f;
    u.f = u.f * (threehalfs - x2 * u.f * u.f); // 1st Newton's iteration
    u.f = u.f * (threehalfs - x2 * u.f * u.f); // 2nd Newton's iteration, can be removed
    // Add more iterations to improve precision
    return u.f * x;
}
