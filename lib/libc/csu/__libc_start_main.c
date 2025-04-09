
__attribute__((noreturn)) void exit(int status);

typedef int (*main_func)(int, char**, char**);

/* __libc_start_main implementation */
int __libc_start_main(int (*main)(int, char**, char**), 
                     int argc, char** argv, char** envp) 
{
    int ret = main(argc, argv, envp);
    exit(ret);
    __builtin_unreachable();
}
