#include <unistd.h>

__attribute__((noreturn)) void exit(int status)
{
	_exit(status);	
}
