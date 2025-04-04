/* _start is the entry point of this new libc */
/* _start is the entry point */
void _start(void) __attribute__((naked));

__attribute__((noreturn)) void exit(int status);

void _start(void)
{
    __asm__ __volatile__(
#ifdef BUILD_EXECUTABLE
#ifdef __APPLE__
        "andq   $-16, %%rsp\n"        /* Align stack first */
        "mov    %%rsp, %%rdi\n"       /* argc */
        "lea    8(%%rsp), %%rsi\n"    /* argv */
        "lea    16(%%rsp), %%rdx\n"   /* envp */
        "call   _main\n"
        "mov    %%rax, %%rdi\n"
        "call   _exit\n"
#else
        "mov %%rsp, %%rbx\n"       // Sauvegarder rsp original
        "andq $-16, %%rsp\n"       // Aligner la pile
        "sub $8, %%rsp\n"          // Éviter la red zone (Sécurité)
        "mov (%%rbx), %%rdi\n"     // argc
        "lea 8(%%rbx), %%rsi\n"    // argv
        "lea 16(%%rbx, %%rdi, 8), %%rdx\n" // envp = argv + argc*8 + 16
        "call main\n"
        "mov %%rax, %%rdi\n"
        "call exit\n"
#endif
#else
        "ret\n"
#endif
        :
        :
        : "rbx", "rdi", "rsi", "rdx", "rax", "rsp", "memory"
    );
}
