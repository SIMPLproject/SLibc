#include <unistd.h>
typedef int (*main_func)(int, char **, char **);

/* __libc_start_main implementation */
int __libc_start_main(int (*main)(int, char **, char **), //
                      int argc, char **argv,              //
                      void (*init)(void),                 //
                      void (*fini)(void),                 //
                      void (*ld_fini)(void),              //
                      void *stack_end)
{
    if (init)
        init();

    char **env = argv + argc + 1;

    int ret = main(argc, argv, env);

    if (fini)
        fini();

    exit(ret);
    __builtin_unreachable();
    (void)ld_fini;
    (void)stack_end;
}
