#include "test_template.h"
#include <stdarg.h>
#include <string.h>

int main()
{

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
    BASIC_TEST("very long string", strlen, 62,
               "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n");
    BASIC_TEST("UTF-8 multibyte characters (é)", strlen, 2, "é"); // multibyte: 0xC3 0xA9
    BASIC_TEST("UTF-8 emoji (😀)", strlen, 4, "😀");              // emoji is 4 bytes
    BASIC_TEST("string with repeated chars", strlen, 10, "aaaaaaaaaa");
    return 0;
}
