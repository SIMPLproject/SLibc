#include "test_template.h"
#include <string.h>

void strlen_test()
{
    printf("\ntesting strlen...\n");
    BASIC_TEST("simple short string", strlen, 5, "test\n");
    BASIC_TEST("empty string", strlen, 0, "");
    BASIC_TEST("string with only newline", strlen, 1, "\n");
    BASIC_TEST("string with space", strlen, 1, " ");
    BASIC_TEST("string with multiple words", strlen, 11, "hello world");
    BASIC_TEST("string with tab character", strlen, 4, "ab\tc");
    BASIC_TEST("string with special characters", strlen, 6, "!@#$%^");
    BASIC_TEST("string with embedded null byte", strlen, 3, "abc\0def"); // strlen should stop at \0
    BASIC_TEST("string with numbers", strlen, 3, "123");
    BASIC_TEST("string with full alphabet", strlen, 26, "abcdefghijklmnopqrstuvwxyz");
    BASIC_TEST("string with leading null", strlen, 0, "\0invisible");
    BASIC_TEST("medium string", strlen, 57,
               "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n");
    BASIC_TEST("long string string", strlen, 1000, STR_1000_a);
    BASIC_TEST("very long string string", strlen, 10000, STR_10000_a);
    BASIC_TEST("very very long string string", strlen, 100000, STR_100000_a);
    BASIC_TEST("UTF-8 multibyte characters (é)", strlen, 2, "é"); // multibyte: 0xC3 0xA9
    BASIC_TEST("UTF-8 emoji (😀)", strlen, 4, "😀");              // emoji is 4 bytes
}

void strcmp_test()
{
    printf("\ntesting strcmp...\n");
    BASIC_TEST("equal strings", strcmp, 0, "hello", "hello");
    BASIC_TEST("prefix match", strcmp, 'a' - '\0', "a", "");
    BASIC_TEST("first is smaller", strcmp, -1, "abc", "abd");
    BASIC_TEST("first is greater", strcmp, 2, "abe", "abc");
    BASIC_TEST("case sensitive", strcmp, 'a' - 'A', "abc", "Abc");
    BASIC_TEST("empty vs non-empty", strcmp, -'h', "", "hello");
    BASIC_TEST("non-empty vs empty", strcmp, 'h', "hello", "");
    BASIC_TEST("null bytes ignored", strcmp, 0, "abc\0xxx", "abc");
    BASIC_TEST("same long string", strcmp, 0, STR_10000_a, STR_10000_a);
    BASIC_TEST("long string with a bad char", strcmp, 1, STR_10000_a "b" STR_10000_a,
               STR_10000_a "a");
}

void strncmp_test()
{
    printf("\ntesting strncmp...\n");
    BASIC_TEST("equal prefix", strncmp, 0, "abcdef", "abcxyz", 3);
    BASIC_TEST("short n equal", strncmp, 0, "abc", "xyz", 0);
    BASIC_TEST("case diff in prefix", strncmp, 'a' - 'A', "abc", "Abc", 1);
    BASIC_TEST("null bytes within n", strncmp, 0, "abc\0def", "abc\0xyz", 4);
    BASIC_TEST("diff after prefix", strncmp, 'd' - 'x', "abcd", "abcx", 4);
    BASIC_TEST("compare empty strings", strncmp, 0, "", "", 10);
    BASIC_TEST("long string prefix equal", strncmp, 0, STR_10000_a, STR_10000_a, 10000);
    BASIC_TEST("long string with extra char", strncmp, 1, STR_10000_a "b", STR_10000_a "a", 10001);
}

void memcpy_test() {
    printf("\ntesting memcpy...\n");
    char src[] = "1234567890";
    char dst[20] = {0};

    memcpy(dst, src, 10);
    BASIC_TEST("basic copy", strcmp, 0, dst, src);

    char big_src[10000], big_dst[10000];
    memset(big_src, 'a', 10000);
    memcpy(big_dst, big_src, 10000);
    BASIC_TEST("large copy", strcmp, 0, big_dst, big_src);
}

void strncpy_test() {
    printf("\ntesting strncpy...\n");
    char buf[10] = {0};

    strncpy(buf, "abc", 5);
    BASIC_TEST("copy short string with padding", strcmp, 0, buf, "abc");

    strncpy(buf, "hello world", 5);
    buf[5] = '\0';
    BASIC_TEST("copy truncated string", strcmp, 0, buf, "hello");

    strncpy(buf, "", 5);
    BASIC_TEST("copy empty string", strcmp, 0, buf, "");
}

void memmove_test() {
    printf("\ntesting memmove...\n");
    char buf1[] = "abcdefghij";
    memmove(buf1 + 2, buf1, 8);
    BASIC_TEST("right overlap", strcmp, 0, buf1 + 2, "abcdefgh");

    char buf2[] = "abcdefghij";
    memmove(buf2, buf2 + 2, 8);
    BASIC_TEST("left overlap", strcmp, 0, buf2, "cdefghij");

    char big[10000];
    for (int i = 0; i < 10000; ++i) big[i] = 'x';
    memmove(big + 10, big, 9990);
    BASIC_TEST("large overlap", strcmp, 0, big + 10, big);
}


int main()
{
    strlen_test();
    strcmp_test();
    strncmp_test();
    memcpy_test();
    strncpy_test();
    return 0;
}
