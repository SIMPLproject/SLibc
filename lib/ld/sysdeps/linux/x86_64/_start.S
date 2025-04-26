/* 
	_start : just call the real start of the linker _dl_start
*/

#include <start.h>

.text
.globl _start
.type _start, @function
.align 16

_start:
	.cfi_startproc
	.cfi_undefined %rip /* tells debuggers that this function has no caller */
	xorl %ebp, %ebp /* clear stack pointer (don't need to clear the entire register) */

	andq $-16, %rsp /* align the stack on 16 */
	sub $8, %rsp /* make it 8-aligned before call (ABI rule) */

	call SIMPL_INTERNAL_SYMBOL(_dl_start)
	call *%rax       /* jump to user entry */
	hlt
    .cfi_endproc
