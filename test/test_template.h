#ifndef __TEST_TEMPALTE_H__
#define __TEST_TEMPALTE_H__

#include <stdio.h>
#include <stdlib.h>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

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

#define BASIC_TEST(description, func, ret, args...)                                                \
    TEST(description, func, BASIC_CMP_RES_FUNC, ret, args)

#endif /* __TEST_TEMPALTE_H__ */
