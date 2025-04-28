#include <sys/symbols.h>
#include <config.h>
#include <unistd.h>
#include <sys/syscall.h> 

__attribute__((noreturn)) void __exit(int status) {
	syscall(SYS_exit, status);
	__builtin_unreachable();
}

simpl_weak_alias(exit, __exit)
libc_hidden_alias(exit, __exit)
