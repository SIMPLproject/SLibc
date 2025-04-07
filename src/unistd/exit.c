#include <unistd.h>
#include <syscall.h>
#include <stdint.h>

void _exit(int status) {
    register uint64_t rax __asm__("rax") = 60;
    register uint64_t rdi __asm__("rdi") = status;

    __asm__ volatile (
        "syscall"
        : /* no outputs */
        : "r"(rax), "r"(rdi)
        : "rcx", "r11", "memory"
    );

    __builtin_unreachable();
}

