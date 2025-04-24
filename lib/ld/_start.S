
/* 
	_start : all args are on the stack by default

	the _start in the entry of the program this is just a jump pad for the 
	__libc_start_main(
			(int (*main) (int, char **, char **),
			int argc,
			char *argv,
			void (*init) (void),
			void (*fini) (void),
			void (*rtld_fini) (void),
			void *stack_end)
	);

	main:		%rdi
	argc:		%rsi
	argv:		%rdx
	init:		%rcx
	fini:		%r8
	ld_fini:	%r9
	stack_end:	stack.	
*/

.text
.globl _start
.type _start, @function
.align 16


_start:
	.cfi_startproc
	movq %rsp, %rbx
	andq $-16, %rsp
	sub $8, %rsp
	ret
    .cfi_endproc



