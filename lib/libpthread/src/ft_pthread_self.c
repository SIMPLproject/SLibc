#include <ft_pthread.h>
#include "sysdeps/ft_pthread_arch.h"

t_pthread	*ft_pthread_self(void)
{
	return ((t_pthread *)__get_tp());
}
