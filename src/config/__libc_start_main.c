
__attribute__((noreturn)) void exit(int status);

typedef int (*main_func)(int, char**, char**);

/* __libc_start_main implementation */
int __libc_start_main(main_func main, int argc, char** argv, char** envp) 
{
    int exit_status = main(argc, argv, envp);
    exit(exit_status);
    return exit_status;  /* This line will never be reached */
}
