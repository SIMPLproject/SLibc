#ifndef __ERRNO_H__
#define __ERRNO_H__

/* need to be change !!!!!!!!!!!!!!!!!! */
extern int errnono = 0;

int *__get_errno_location(void) { return &errnono; }

#define __set_errno(value) (*__get_errno_location() = value)

#endif /* __ERRNO_H__ */
