#include "ft_pthread.h"
#include <errno.h>
#include <linux/sched.h>
#include <syscall.h>
#include <unistd.h>

int clone(int (*fn)(void *), void *child_stack, int flags, void *args);

int ft_clone(int (*fn)(void *), void *child_stack, int flags, void *args)
{
    return clone(fn, child_stack, flags, args);
}

int ft_clone3(int (*fn)(void *), void *arg, struct clone_args *cl_args) {
    long ret;
    size_t args_size = sizeof(*cl_args);  // This should be small (e.g., 88 bytes)
    __asm__ volatile (
        "test %%rdi, %%rdi\n\t"         /* Check cl_args != NULL */
        "jz 1f\n\t"
        "test %%rdx, %%rdx\n\t"         /* Check fn != NULL */
        "jz 1f\n\t"
        "mov %%rcx, %%r8\n\t"           /* Save function argument (arg) into R8 */
        "mov %%rdx, %%r12\n\t"          /* Save function pointer (fn) into R12 */
        "movl %[sys_clone3], %%eax\n\t" /* Set syscall number for clone3 */
        "syscall\n\t"                   /* Execute clone3 syscall */
        "test %%rax, %%rax\n\t"
        "jl 1f\n\t"                     /* If ret < 0, error */
        "jz 2f\n\t"                     /* If ret == 0, child */
        "jmp 3f\n\t"
        "1:\n\t"                        /* Error path */
        "movl $-22, %%eax\n\t"          /* -EINVAL (-22) */
        "jmp 3f\n\t"
        "2:\n\t"                        /* Child thread path */
        "xorl %%ebp, %%ebp\n\t"          /* Clear frame pointer */
        "mov %%r8, %%rdi\n\t"            /* Set RDI = arg */
        "call *%%r12\n\t"               /* Call function pointer */
        "mov %%rax, %%rdi\n\t"           /* Return value for exit */
        "movl %[sys_exit], %%eax\n\t"    /* Set syscall number for exit */
        "syscall\n\t"
        "3:"                           /* End label */
        : "=a" (ret)
        : "D" (cl_args), "d" (fn), "c" (arg),
          [sys_clone3] "i" (SYS_clone3),
          [sys_exit] "i" (SYS_exit),
          "S" (args_size)
        : "r8", "r11", "r12", "memory"
    );
    return ret;
}
