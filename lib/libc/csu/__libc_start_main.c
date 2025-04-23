
__attribute__((noreturn)) void exit(int status);

__attribute__((weak)) void __libc_thread_init(void) {}
__attribute__((weak)) void __libc_malloc_init(void) {}

typedef int (*main_func)(int, char **, char **);

/* __libc_start_main implementation */
int __libc_start_main(int (*main)(int, char **, char **), //
                      int argc, char **argv, char **envp, //
                      void (*init)(void),                 //
                      void (*fini)(void),                 //
                      void (*ld_fini)(void),              //
                      void *stack_end)
{
    if (init)
        init();
    __libc_thread_init();

    int ret = main(argc, argv, envp);

    if (fini)
        fini();

    if (ld_fini)
        ld_fini();

    exit(ret);
    __builtin_unreachable();
    (void)stack_end;
}
