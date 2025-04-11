/* _start is the entry point of this new libc */
/* _start is the entry point */
void _start(void) __attribute__((naked));

#include <unistd.h>

void _start(void)
{
    __asm__ __volatile__(
        "mov %%rsp, %%rbx\n"       // Sauvegarder rsp original
        "andq $-16, %%rsp\n"       // Aligner la pile
        "sub $8, %%rsp\n"          // Éviter la red zone (Sécurité)
        "mov (%%rbx), %%rdi\n"     // argc
        "lea 8(%%rbx), %%rsi\n"    // argv
        "lea 16(%%rbx, %%rdi, 8), %%rdx\n" // envp = argv + argc*8 + 16
        "call main\n"
        "mov %%rax, %%rdi\n"
        "call exit\n"
        :
        :
        : "rbx", "rdi", "rsi", "rdx", "rax", "rsp", "memory"
    );
}
