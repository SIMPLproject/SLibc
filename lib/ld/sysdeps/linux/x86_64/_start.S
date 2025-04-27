/* 
	_start : just call the real start of the linker _dl_start
*/

.text
.globl _start
.type _start, @function
.align 16

.extern _ld_start

_start:
	.cfi_startproc
	.cfi_undefined %rip /* tells debuggers that this function has no caller */
	xorl %ebp, %ebp /* clear stack pointer (don't need to clear the entire register) */

	andq $-16, %rsp /* align the stack on 16 */
	sub $8, %rsp /* make it 8-aligned before call (ABI rule) */

	call _ld_start
	call *%rax       /* jump to user entry */
	hlt
    .cfi_endproc
