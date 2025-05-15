#include "sys/cdefs.h"
#include "sys/symbols.h"
#include <string.h>
#include <unistd.h>

int __puts(const char* str)
{
	return write(1, str, strlen(str));
}

libc_hidden_alias(puts, __puts)
simpl_weak_alias(puts, __puts)

