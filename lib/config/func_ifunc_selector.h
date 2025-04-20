#ifndef __FUNC_IFUNC_SELECTOR_H__
#define __FUNC_IFUNC_SELECTOR_H__

/*
 * - if compile in shared this will make a ifunc will all suported version of the function
 * - if compile in native (shared or archive) will only compile the best version for the arch and
 * weak alias it
 * - if not shared just simlink the base
 */

#if defined(SHARED)

#    include "cpuid_conf.h"

enum ifunc_type_u {
    IFUNC_MMX = 1u,
    IFUNC_SSE = (1u << 1),
    IFUNC_AVX = (1u << 2),
    IFUNC_ERMS = (1u << 3),
};

#    include <stdio.h>
#    ifdef VERBOSE
#        define IFUNC_LOG(func) printf("ifunc %s is selected\n", #func);
#    else
#        define IFUNC_LOG(func)
#    endif

#    define _func_selected(func)                                                                   \
        {                                                                                          \
            IFUNC_LOG(func)                                                                        \
            return func;                                                                           \
        }

#    define __ifunc_create_prototype(name, type_name, ...)                                         \
        type_name name##_avx(__VA_ARGS__);                                                         \
        type_name name##_sse(__VA_ARGS__);                                                         \
        type_name name##_generic(__VA_ARGS__);

#    define __ifunc_creator(name, type_name, _version, ...)                                        \
        type_name (*name##_ifunc())(__VA_ARGS__)                                                   \
        {                                                                                          \
            uint8_t version = _version;                                                            \
            if ((version & IFUNC_AVX) && simd_support.avx)                                         \
            {                                                                                      \
                _func_selected(name##_avx)                                                         \
            }                                                                                      \
            if ((version & IFUNC_SSE) && simd_support.sse)                                         \
            {                                                                                      \
                _func_selected(name##_sse)                                                         \
            }                                                                                      \
            _func_selected(name##_generic)                                                         \
        }
#    define simpl_func_ifunc_init(name, type_name, version, ...)                                   \
        extern type_name name(__VA_ARGS__) __attribute__((ifunc(#name "_ifunc")));                 \
        __ifunc_create_prototype(name, type_name, __VA_ARGS__)                                     \
            __ifunc_creator(name, type_name, version, __VA_ARGS__)
#endif

#endif /* __FUNC_IFUNC_SELECTOR_H__ */
