#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


int tsprintf(const char *format, ...)
{
    char    print_buff[256];
    va_list lst;

    va_start(lst, format);
    int len = vsnprintf(print_buff, 256, format, lst);
    va_end(lst);

    write(2, print_buff, len);

    return len;
}
