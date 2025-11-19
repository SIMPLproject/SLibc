#include <link.h>

/*
 * Debugging descriptor for debuggers (GDB uses this)
 */
struct r_debug _r_debug = {
    .r_version = 1,           //
    .r_map = 0,               //
    .r_brk = 0,               //
    .r_state = RT_CONSISTENT, //
    .r_ldbase = 0             //
};
