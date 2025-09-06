#include <pthread.h>
#include "sysdeps/ft_pthread_arch.h"

pthread_t	*ft_pthread_self(void)
{
	return ((pthread_t *)__get_tp());
}
