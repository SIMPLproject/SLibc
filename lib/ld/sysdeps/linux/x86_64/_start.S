/* 
	_start : just call the real start of the linker _dl_start
*/

#include <sys/symbols.h>

.text
.globl _start
.type _start, @function
.align 16

.extern _ld_start
.hidden _ld_start

_start:
	.cfi_startproc
	.cfi_undefined %rip /* tells debuggers that this function has no caller */
	xorl %ebp, %ebp /* clear stack pointer (don't need to clear the entire register) */

	call _ld_start

	call *%rax       /* jump to user entry */
	hlt
    .cfi_endproc
