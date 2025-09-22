#include <config.h>
#include <stddef.h>

size_t ARCH_SYM(strlen)(const char *str);

size_t slibc_strlen(const char *str)
{
    return ARCH_SYM(strlen)(str);
}
