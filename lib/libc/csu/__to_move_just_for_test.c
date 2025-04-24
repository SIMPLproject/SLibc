#include <stdio.h>
#include <unistd.h>

__attribute__((noreturn)) void __stack_chk_fail(void) {
	printf("SLibc : stack go boom !!!");
	exit(1); 
	__builtin_unreachable();
}
