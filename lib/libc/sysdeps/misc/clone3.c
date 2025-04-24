#include <stdint.h>
#include <stddef.h>
#include <sys/cdefs.h>
#include <errno.h>

struct clone_args {
    uint64_t flags;        /* Flags bit mask */
    uint64_t pidfd;        /* Where to store PID file descriptor
                         (int *) */
    uint64_t child_tid;    /* Where to store child TID,
                         in child's memory (pid_t *) */
    uint64_t parent_tid;   /* Where to store child TID,
                         in parent's memory (pid_t *) */
    uint64_t exit_signal;  /* Signal to deliver to parent on
                         child termination */
    uint64_t stack;        /* Pointer to lowest byte of stack */
    uint64_t stack_size;   /* Size of stack */
    uint64_t tls;          /* Location of new TLS */
    uint64_t set_tid;      /* Pointer to a pid_t array
                         (since Linux 5.5) */
    uint64_t set_tid_size; /* Number of elements in set_tid
                         (since Linux 5.5) */
    uint64_t cgroup;       /* File descriptor for target cgroup
                         of child (since Linux 5.7) */
};

#define __unused __attribute__((unused))

int clone3(struct clone_args *cl_args __unused,
		   size_t cl_args_size __unused,
		   int (*fn)(void *args) __unused,
		   void *args __unused)
{
	__set_errno(1);
	return -1;
}


