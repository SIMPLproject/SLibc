#include <stdio.h>
#include <unistd.h>
#include <sys/cdefs.h>

__no_return void __stack_chk_fail(void) {
	printf("SLibc : stack go boom !!!");
	exit(1); 
	__builtin_unreachable();
}
