#include "test_template.h"
#include <string.h>

void strlen_test() {
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
    BASIC_TEST("medium string", strlen, 57, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n");
    BASIC_TEST("long string string", strlen, 1000, STR_1000_a);
    BASIC_TEST("very long string string", strlen, 10000, STR_10000_a);
    BASIC_TEST("very very long string string", strlen, 100000, STR_100000_a);
    BASIC_TEST("UTF-8 multibyte characters (é)", strlen, 2, "é"); // multibyte: 0xC3 0xA9
    BASIC_TEST("UTF-8 emoji (😀)", strlen, 4, "😀");              // emoji is 4 bytes
}

void strcmp_test() {
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
    BASIC_TEST("long string with a bad char", strcmp, 1, STR_10000_a "b" STR_10000_a, STR_10000_a "a");
}

void strncmp_test() {
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

int main()
{
	strlen_test();
	strcmp_test();
	strncmp_test();
    return 0;
}
