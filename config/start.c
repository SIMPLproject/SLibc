/* _start is the entry point of this new libc */
void _start(void) __attribute__((naked));

void _start(void)
{
#ifdef __APPLE__
    __asm__ __volatile__
    (
#ifdef BUILD_EXECUTABLE
        "mov rsp, rdi\n"             /* Set up arguments for main */
        "lea rsi, [rsp + 8]\n"       /* Load argv into rsi */
        "mov rdx, rsi\n"             /* Move envp to rdx */
        "add rdx, 8\n"               /* Adjust envp */
        "and rsp, -16\n"             /* Align stack pointer to 16 bytes */
        "call _main\n"               /* Call main function */
        "mov rdi, rax\n"             /* Save return value */
        "call _exit\n"               /* Call exit function */
#else
        "ret\n"                      /* For library, just return */
#endif
        :
        :
        : "rdi", "rsi", "rdx", "rax"    /* Clobbered registers */
    );
#else
    __asm__ __volatile__
    (
        "mov %%rsp, %%rdi\n"          /* Set up arguments for main */
        "lea 8(%%rsp), %%rsi\n"       /* Load argv into rsi */
        "mov %%rsi, %%rdx\n"          /* Move envp to rdx */
        "add $8, %%rdx\n"             /* Adjust envp */
        "andq $-16, %%rsp\n"          /* Align stack pointer to 16 bytes */
        "call main\n"                 /* Call main function */
        "mov %%rax, %%rdi\n"          /* Save return value */
        "call exit\n"                 /* Call exit function */
        "ret\n"                       /* For library, just return */
        :
        :
        : "rdi", "rsi", "rdx", "rax"  /* Clobbered registers */
    );
#endif
}
