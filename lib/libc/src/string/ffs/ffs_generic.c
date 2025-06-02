#include <config.h>

int ARCH_SYM(ffs)(int x)
{
    if (x == 0)
        return 0;

    int position = 1;
    while ((x & 1) == 0)
    {
        x >>= 1;
        position++;
    }
    return position;
}
