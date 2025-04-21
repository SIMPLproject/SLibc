#include <unistd.h>

__attribute__((noreturn)) void __stack_chk_fail(void) {
	exit(1); 
	__builtin_unreachable();
}
