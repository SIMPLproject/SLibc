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
	.cfi_undefined %rip /* tells debuggers that this function has no caller */
	xorl %ebp, %ebp /* clear stack pointer (don't need to clear the entire register) */

	/* args for __libc_start_main */
	movq %rdx, %r9 /* for the ld_fini when starting form the dynamic loader */
	leaq main(%rip), %rdi	/* main */
	popq %rsi				/* argc */
	movq %rsp, %rdx			/* argv */
	xorq %rcx, %rcx			/* init */
	xorq %r8, %r8			/* fini */

	andq $-16, %rsp /* align the stack on 16 */
	sub $8, %rsp /* make it 8-aligned before call (ABI rule) */


	pushq %rax
	pushq %rsp
	
	call __libc_start_main
	hlt /* __libc_start_main never return normaly... so this will segfault */
    .cfi_endproc



