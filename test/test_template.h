#ifndef __TEST_TEMPALTE_H__
#define __TEST_TEMPALTE_H__

#include <stdio.h>
#include <stdlib.h>

#ifdef NO_TEST_EXIT
#    define TEST_EXIT
#else
#    define TEST_EXIT exit(1);
#endif

#define TEST(description, func, cmp_res_func, ret, args...)                                        \
    {                                                                                              \
        ft_printf("%s test %d [%s]: %s\t", __FILE__, __COUNTER__, #func, description);             \
        if (cmp_res_func(ret, func(args)))                                                         \
        {                                                                                          \
            printf("pass\n");                                                                      \
        } else                                                                                     \
        {                                                                                          \
            printf("error\n");                                                                     \
            TEST_EXIT                                                                              \
        }                                                                                          \
    }

#define BASIC_CMP_RES_FUNC(res, func_res) (res == func_res)

#define BASIC_TEST(description, func, ret, args...)                                                \
    TEST(description, func, BASIC_CMP_RES_FUNC, ret, args)

#endif /* __TEST_TEMPALTE_H__ */
