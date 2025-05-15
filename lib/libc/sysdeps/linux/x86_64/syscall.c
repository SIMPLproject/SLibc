#include <sys/symbols.h>
#include <config.h>
#include <stdarg.h>

long __syscall(long number, ...)
{
    va_list args;
    va_start(args, number);

    unsigned long arg1 = va_arg(args, unsigned long);
    unsigned long arg2 = va_arg(args, unsigned long);
    unsigned long arg3 = va_arg(args, unsigned long);
    unsigned long arg4 = va_arg(args, unsigned long);
    unsigned long arg5 = va_arg(args, unsigned long);
    unsigned long arg6 = va_arg(args, unsigned long);

    va_end(args);

    register long rax __asm__("rax") = number;
    register long rdi __asm__("rdi") = arg1;
    register long rsi __asm__("rsi") = arg2;
    register long rdx __asm__("rdx") = arg3;
    register long r10 __asm__("r10") = arg4;
    register long r8  __asm__("r8")  = arg5;
    register long r9  __asm__("r9")  = arg6;

    __asm__ volatile (
        "syscall"
        : "+r"(rax)
        : "r"(rdi), "r"(rsi), "r"(rdx), "r"(r10), "r"(r8), "r"(r9)
        : "rcx", "r11", "memory"
    );

    return rax;
}


simpl_weak_alias(syscall, __syscall)
simpl_hidden_alias(syscall, __syscall)
