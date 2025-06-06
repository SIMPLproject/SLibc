#ifndef __TEST_TEMPALTE_H__
#define __TEST_TEMPALTE_H__

#include <stdio.h>
#include <stdlib.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#ifdef NO_TEST_EXIT
#    define TEST_EXIT
#else
#    define TEST_EXIT exit(1);
#endif

#define TEST(description, func, cmp_res_func, expected, args...)                                   \
    {                                                                                              \
        int result = func(args);                                                                   \
        if (cmp_res_func(expected, result))                                                        \
        {                                                                                          \
            printf(GREEN "[PASS]" RESET " %s => expected: %d, got: %d\n", description, expected,   \
                   result);                                                                        \
        } else                                                                                     \
        {                                                                                          \
            printf(RED "[FAIL]" RESET " %s => expected: %d, got: %d\n", description, expected,     \
                   result);                                                                        \
            TEST_EXIT                                                                              \
        }                                                                                          \
    }

#define BASIC_CMP_RES_FUNC(res, func_res) (res == func_res)
#define BASIC_CMP_RES_FUNC_ADDR(res, func_res) (res == &func_res)
#define BASIC_CMP_RES_FUNC_PTR_VALUE(res, func_res) (res == *func_res)

#define BASIC_TEST_ADDRESS(description, func, ret, args...)                                        \
    TEST(description, func, BASIC_CMP_RES_FUNC_ADDR, ret, args)

#define BASIC_TEST_PTR_VALUE(description, func, ret, args...)                                      \
    TEST(description, func, BASIC_CMP_RES_FUNC_PTR_VALUE, ret, args)

#define BASIC_TEST(description, func, ret, args...)                                                \
    TEST(description, func, BASIC_CMP_RES_FUNC, ret, args)

#define STR_1000_a                                                                                 \
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
#define STR_10000_a                                                                                \
    STR_1000_a STR_1000_a STR_1000_a STR_1000_a STR_1000_a STR_1000_a STR_1000_a STR_1000_a        \
        STR_1000_a STR_1000_a
#define STR_100000_a                                                                               \
    STR_10000_a STR_10000_a STR_10000_a STR_10000_a STR_10000_a STR_10000_a STR_10000_a            \
        STR_10000_a STR_10000_a STR_10000_a

#endif /* __TEST_TEMPALTE_H__ */
