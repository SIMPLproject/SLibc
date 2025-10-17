#ifndef __ERRNO_H__
#define __ERRNO_H__

#include <sys/errno_table.h>

int *__get_errno_location(void);

#define __set_errno(value) (*__get_errno_location() = (value))

#define errno (*__set_errno_location())

#endif /* __ERRNO_H__ */
