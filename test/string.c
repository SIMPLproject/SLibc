#include "test_template.h"
#include <string.h>

int __strcmp_generic (const char *__s1, const char *__s2);

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
    BASIC_TEST("basic copy", __strcmp_generic, 0, dst, src);

    char big_src[10000], big_dst[10000];
    memset(big_src, 'a', 10000);
    memcpy(big_dst, big_src, 10000);
    BASIC_TEST("large copy", __strcmp_generic, 0, big_dst, big_src);
}

// void strncpy_test() {
//     printf("\ntesting strncpy...\n");
//     char buf[10] = {0};
//
//     strncpy(buf, "abc", 5);
//     BASIC_TEST("copy short string with padding", strcmp, 0, buf, "abc");
//
//     strncpy(buf, "hello world", 5);
//     buf[5] = '\0';
//     BASIC_TEST("copy truncated string", strcmp, 0, buf, "hello");
//
//     strncpy(buf, "", 5);
//     BASIC_TEST("copy empty string", strcmp, 0, buf, "");
// }

void memmove_test() {
    printf("\ntesting memmove...\n");
    char buf1[] = "abcdefghij";
    memmove(buf1 + 2, buf1, 8);
    BASIC_TEST("right overlap", __strcmp_generic, 0, buf1 + 2, "abcdefgh");

    char buf2[] = "abcdefghij";
    memmove(buf2, buf2 + 2, 8);
    BASIC_TEST("left overlap", __strcmp_generic, 0, buf2, "cdefghij");

    char big[10000];
    for (int i = 0; i < 10000; ++i) big[i] = 'x';
    memmove(big + 10, big, 9990);
    BASIC_TEST("large overlap", __strcmp_generic, 0, big + 10, big);
}




void memset_test(void) {
    printf("\ntesting memset...\n");

    // fill full buffer
    {
        char buf[11];
        memset(buf, 'a', 10);
        buf[10] = '\0';
        BASIC_TEST("fill 10 'a'", __strcmp_generic, 0, buf, "aaaaaaaaaa");
    }

    // partial fill in the middle
    {
        char buf[] = "abcdefghij";
        memset(buf + 2, 'Z', 5); // abcdefghij -> abZZZZZhij
        BASIC_TEST("partial middle fill", __strcmp_generic, 0, buf, "abZZZZZhij");
    }

    // zero length: no change
    {
        char buf[] = "abc";
        memset(buf, 'X', __extension__ 0);
        BASIC_TEST("zero length no-op", __strcmp_generic, 0, buf, "abc");
    }

    // small prefix fill (checks that only first N bytes are changed)
    {
        char buf[] = "abcdefghij";
        memset(buf, 'q', 3); // -> qqqdefghij
        BASIC_TEST("prefix fill 3", __strcmp_generic, 0, buf, "qqqdefghij");
    }

    // size 1 fill
    {
        char buf[] = "abcdefghij";
        memset(buf + 9, 'K', 1); // last char only
        BASIC_TEST("size 1 fill", __strcmp_generic, 0, buf, "abcdefghiK");
    }

    // non-ASCII byte value (0xAB) — ensure it’s treated as unsigned char
    {
        unsigned char b1[9], e1[9];
        memset(b1, 0xAB, 8); b1[8] = 0;   // NUL-terminate for __strcmp_generic
        memset(e1, 0xAB, 8); e1[8] = 0;
        BASIC_TEST("fill 0xAB bytes", __strcmp_generic, 0, (char *)b1, (char *)e1);
    }

    // negative value (-1) should become 0xFF
    {
        unsigned char b1[9], e1[9];
        memset(b1, -1, 8); b1[8] = 0;
        memset(e1, 0xFF, 8); e1[8] = 0;
        BASIC_TEST("fill -1 -> 0xFF", __strcmp_generic, 0, (char *)b1, (char *)e1);
    }

    // large fill
    {
        char big[10001], exp[10001];
        memset(big, 'x', 10000); big[10000] = '\0';
        memset(exp, 'x', 10000); exp[10000] = '\0';
        BASIC_TEST("large fill 10k", __strcmp_generic, 0, big, exp);
    }
}


int main()
{
    strlen_test();
    strcmp_test();
    strncmp_test();
    memcpy_test();
	memset_test();
    // strncpy_test();
    return 0;
}
