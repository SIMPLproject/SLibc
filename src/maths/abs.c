#include "libmath.h"

double fabs(double x) {
    union {float f; long i;} u = { x };
    u.i &= ~(1ull << 63); // Set sign to 0 makes it positive
    return u.f;
}

int abs(int x) {
    return x < 0 ? -x : x;
}
