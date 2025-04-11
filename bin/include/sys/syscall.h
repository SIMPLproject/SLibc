#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#include <bits/syscall_table.h>

#define __MISC -1

#if defined(__SYS_read)
#    define SYS_read __SYS_read
#else
#    define SYS_read __MISC
#endif

#if defined(__SYS_write)
#    define SYS_write __SYS_write
#else
#    define SYS_write __MISC
#endif

#if defined(__SYS_open)
#    define SYS_open __SYS_open
#else
#    define SYS_open __MISC
#endif

#if defined(__SYS_close)
#    define SYS_close __SYS_close
#else
#    define SYS_close __MISC
#endif

#if defined(__SYS_stat)
#    define SYS_stat __SYS_stat
#else
#    define SYS_stat __MISC
#endif

#if defined(__SYS_fstat)
#    define SYS_fstat __SYS_fstat
#else
#    define SYS_fstat __MISC
#endif

#if defined(__SYS_lstat)
#    define SYS_lstat __SYS_lstat
#else
#    define SYS_lstat __MISC
#endif

#if defined(__SYS_poll)
#    define SYS_poll __SYS_poll
#else
#    define SYS_poll __MISC
#endif

#if defined(__SYS_lseek)
#    define SYS_lseek __SYS_lseek
#else
#    define SYS_lseek __MISC
#endif

#if defined(__SYS_mmap)
#    define SYS_mmap __SYS_mmap
#else
#    define SYS_mmap __MISC
#endif

#if defined(__SYS_mprotect)
#    define SYS_mprotect __SYS_mprotect
#else
#    define SYS_mprotect __MISC
#endif

#if defined(__SYS_munmap)
#    define SYS_munmap __SYS_munmap
#else
#    define SYS_munmap __MISC
#endif

#if defined(__SYS_brk)
#    define SYS_brk __SYS_brk
#else
#    define SYS_brk __MISC
#endif

#if defined(__SYS_rt_sigaction)
#    define SYS_rt_sigaction __SYS_rt_sigaction
#else
#    define SYS_rt_sigaction __MISC
#endif

#if defined(__SYS_rt_sigprocmask)
#    define SYS_rt_sigprocmask __SYS_rt_sigprocmask
#else
#    define SYS_rt_sigprocmask __MISC
#endif

#if defined(__SYS_rt_sigreturn)
#    define SYS_rt_sigreturn __SYS_rt_sigreturn
#else
#    define SYS_rt_sigreturn __MISC
#endif

#if defined(__SYS_ioctl)
#    define SYS_ioctl __SYS_ioctl
#else
#    define SYS_ioctl __MISC
#endif

#if defined(__SYS_pread64)
#    define SYS_pread64 __SYS_pread64
#else
#    define SYS_pread64 __MISC
#endif

#if defined(__SYS_pwrite64)
#    define SYS_pwrite64 __SYS_pwrite64
#else
#    define SYS_pwrite64 __MISC
#endif

#if defined(__SYS_readv)
#    define SYS_readv __SYS_readv
#else
#    define SYS_readv __MISC
#endif

#if defined(__SYS_writev)
#    define SYS_writev __SYS_writev
#else
#    define SYS_writev __MISC
#endif

#if defined(__SYS_access)
#    define SYS_access __SYS_access
#else
#    define SYS_access __MISC
#endif

#if defined(__SYS_pipe)
#    define SYS_pipe __SYS_pipe
#else
#    define SYS_pipe __MISC
#endif

#if defined(__SYS_select)
#    define SYS_select __SYS_select
#else
#    define SYS_select __MISC
#endif

#if defined(__SYS_sched_yield)
#    define SYS_sched_yield __SYS_sched_yield
#else
#    define SYS_sched_yield __MISC
#endif

#if defined(__SYS_mremap)
#    define SYS_mremap __SYS_mremap
#else
#    define SYS_mremap __MISC
#endif

#if defined(__SYS_msync)
#    define SYS_msync __SYS_msync
#else
#    define SYS_msync __MISC
#endif

#if defined(__SYS_mincore)
#    define SYS_mincore __SYS_mincore
#else
#    define SYS_mincore __MISC
#endif

#if defined(__SYS_madvise)
#    define SYS_madvise __SYS_madvise
#else
#    define SYS_madvise __MISC
#endif

#if defined(__SYS_shmget)
#    define SYS_shmget __SYS_shmget
#else
#    define SYS_shmget __MISC
#endif

#if defined(__SYS_shmat)
#    define SYS_shmat __SYS_shmat
#else
#    define SYS_shmat __MISC
#endif

#if defined(__SYS_shmctl)
#    define SYS_shmctl __SYS_shmctl
#else
#    define SYS_shmctl __MISC
#endif

#if defined(__SYS_dup)
#    define SYS_dup __SYS_dup
#else
#    define SYS_dup __MISC
#endif

#if defined(__SYS_dup2)
#    define SYS_dup2 __SYS_dup2
#else
#    define SYS_dup2 __MISC
#endif

#if defined(__SYS_pause)
#    define SYS_pause __SYS_pause
#else
#    define SYS_pause __MISC
#endif

#if defined(__SYS_nanosleep)
#    define SYS_nanosleep __SYS_nanosleep
#else
#    define SYS_nanosleep __MISC
#endif

#if defined(__SYS_getitimer)
#    define SYS_getitimer __SYS_getitimer
#else
#    define SYS_getitimer __MISC
#endif

#if defined(__SYS_alarm)
#    define SYS_alarm __SYS_alarm
#else
#    define SYS_alarm __MISC
#endif

#if defined(__SYS_setitimer)
#    define SYS_setitimer __SYS_setitimer
#else
#    define SYS_setitimer __MISC
#endif

#if defined(__SYS_getpid)
#    define SYS_getpid __SYS_getpid
#else
#    define SYS_getpid __MISC
#endif

#if defined(__SYS_sendfile)
#    define SYS_sendfile __SYS_sendfile
#else
#    define SYS_sendfile __MISC
#endif

#if defined(__SYS_socket)
#    define SYS_socket __SYS_socket
#else
#    define SYS_socket __MISC
#endif

#if defined(__SYS_connect)
#    define SYS_connect __SYS_connect
#else
#    define SYS_connect __MISC
#endif

#if defined(__SYS_accept)
#    define SYS_accept __SYS_accept
#else
#    define SYS_accept __MISC
#endif

#if defined(__SYS_sendto)
#    define SYS_sendto __SYS_sendto
#else
#    define SYS_sendto __MISC
#endif

#if defined(__SYS_recvfrom)
#    define SYS_recvfrom __SYS_recvfrom
#else
#    define SYS_recvfrom __MISC
#endif

#if defined(__SYS_sendmsg)
#    define SYS_sendmsg __SYS_sendmsg
#else
#    define SYS_sendmsg __MISC
#endif

#if defined(__SYS_recvmsg)
#    define SYS_recvmsg __SYS_recvmsg
#else
#    define SYS_recvmsg __MISC
#endif

#if defined(__SYS_shutdown)
#    define SYS_shutdown __SYS_shutdown
#else
#    define SYS_shutdown __MISC
#endif

#if defined(__SYS_bind)
#    define SYS_bind __SYS_bind
#else
#    define SYS_bind __MISC
#endif

#if defined(__SYS_listen)
#    define SYS_listen __SYS_listen
#else
#    define SYS_listen __MISC
#endif

#if defined(__SYS_getsockname)
#    define SYS_getsockname __SYS_getsockname
#else
#    define SYS_getsockname __MISC
#endif

#if defined(__SYS_getpeername)
#    define SYS_getpeername __SYS_getpeername
#else
#    define SYS_getpeername __MISC
#endif

#if defined(__SYS_socketpair)
#    define SYS_socketpair __SYS_socketpair
#else
#    define SYS_socketpair __MISC
#endif

#if defined(__SYS_setsockopt)
#    define SYS_setsockopt __SYS_setsockopt
#else
#    define SYS_setsockopt __MISC
#endif

#if defined(__SYS_getsockopt)
#    define SYS_getsockopt __SYS_getsockopt
#else
#    define SYS_getsockopt __MISC
#endif

#if defined(__SYS_clone)
#    define SYS_clone __SYS_clone
#else
#    define SYS_clone __MISC
#endif

#if defined(__SYS_fork)
#    define SYS_fork __SYS_fork
#else
#    define SYS_fork __MISC
#endif

#if defined(__SYS_vfork)
#    define SYS_vfork __SYS_vfork
#else
#    define SYS_vfork __MISC
#endif

#if defined(__SYS_execve)
#    define SYS_execve __SYS_execve
#else
#    define SYS_execve __MISC
#endif

#if defined(__SYS_exit)
#    define SYS_exit __SYS_exit
#else
#    define SYS_exit __MISC
#endif

#if defined(__SYS_wait4)
#    define SYS_wait4 __SYS_wait4
#else
#    define SYS_wait4 __MISC
#endif

#if defined(__SYS_kill)
#    define SYS_kill __SYS_kill
#else
#    define SYS_kill __MISC
#endif

#if defined(__SYS_uname)
#    define SYS_uname __SYS_uname
#else
#    define SYS_uname __MISC
#endif

#if defined(__SYS_semget)
#    define SYS_semget __SYS_semget
#else
#    define SYS_semget __MISC
#endif

#if defined(__SYS_semop)
#    define SYS_semop __SYS_semop
#else
#    define SYS_semop __MISC
#endif

#if defined(__SYS_semctl)
#    define SYS_semctl __SYS_semctl
#else
#    define SYS_semctl __MISC
#endif

#if defined(__SYS_shmdt)
#    define SYS_shmdt __SYS_shmdt
#else
#    define SYS_shmdt __MISC
#endif

#if defined(__SYS_msgget)
#    define SYS_msgget __SYS_msgget
#else
#    define SYS_msgget __MISC
#endif

#if defined(__SYS_msgsnd)
#    define SYS_msgsnd __SYS_msgsnd
#else
#    define SYS_msgsnd __MISC
#endif

#if defined(__SYS_msgrcv)
#    define SYS_msgrcv __SYS_msgrcv
#else
#    define SYS_msgrcv __MISC
#endif

#if defined(__SYS_msgctl)
#    define SYS_msgctl __SYS_msgctl
#else
#    define SYS_msgctl __MISC
#endif

#if defined(__SYS_fcntl)
#    define SYS_fcntl __SYS_fcntl
#else
#    define SYS_fcntl __MISC
#endif

#if defined(__SYS_flock)
#    define SYS_flock __SYS_flock
#else
#    define SYS_flock __MISC
#endif

#if defined(__SYS_fsync)
#    define SYS_fsync __SYS_fsync
#else
#    define SYS_fsync __MISC
#endif

#if defined(__SYS_fdatasync)
#    define SYS_fdatasync __SYS_fdatasync
#else
#    define SYS_fdatasync __MISC
#endif

#if defined(__SYS_truncate)
#    define SYS_truncate __SYS_truncate
#else
#    define SYS_truncate __MISC
#endif

#if defined(__SYS_ftruncate)
#    define SYS_ftruncate __SYS_ftruncate
#else
#    define SYS_ftruncate __MISC
#endif

#if defined(__SYS_getdents)
#    define SYS_getdents __SYS_getdents
#else
#    define SYS_getdents __MISC
#endif

#if defined(__SYS_getcwd)
#    define SYS_getcwd __SYS_getcwd
#else
#    define SYS_getcwd __MISC
#endif

#if defined(__SYS_chdir)
#    define SYS_chdir __SYS_chdir
#else
#    define SYS_chdir __MISC
#endif

#if defined(__SYS_fchdir)
#    define SYS_fchdir __SYS_fchdir
#else
#    define SYS_fchdir __MISC
#endif

#if defined(__SYS_rename)
#    define SYS_rename __SYS_rename
#else
#    define SYS_rename __MISC
#endif

#if defined(__SYS_mkdir)
#    define SYS_mkdir __SYS_mkdir
#else
#    define SYS_mkdir __MISC
#endif

#if defined(__SYS_rmdir)
#    define SYS_rmdir __SYS_rmdir
#else
#    define SYS_rmdir __MISC
#endif

#if defined(__SYS_creat)
#    define SYS_creat __SYS_creat
#else
#    define SYS_creat __MISC
#endif

#if defined(__SYS_link)
#    define SYS_link __SYS_link
#else
#    define SYS_link __MISC
#endif

#if defined(__SYS_unlink)
#    define SYS_unlink __SYS_unlink
#else
#    define SYS_unlink __MISC
#endif

#if defined(__SYS_symlink)
#    define SYS_symlink __SYS_symlink
#else
#    define SYS_symlink __MISC
#endif

#if defined(__SYS_readlink)
#    define SYS_readlink __SYS_readlink
#else
#    define SYS_readlink __MISC
#endif

#if defined(__SYS_chmod)
#    define SYS_chmod __SYS_chmod
#else
#    define SYS_chmod __MISC
#endif

#if defined(__SYS_fchmod)
#    define SYS_fchmod __SYS_fchmod
#else
#    define SYS_fchmod __MISC
#endif

#if defined(__SYS_chown)
#    define SYS_chown __SYS_chown
#else
#    define SYS_chown __MISC
#endif

#if defined(__SYS_fchown)
#    define SYS_fchown __SYS_fchown
#else
#    define SYS_fchown __MISC
#endif

#if defined(__SYS_lchown)
#    define SYS_lchown __SYS_lchown
#else
#    define SYS_lchown __MISC
#endif

#if defined(__SYS_umask)
#    define SYS_umask __SYS_umask
#else
#    define SYS_umask __MISC
#endif

#if defined(__SYS_gettimeofday)
#    define SYS_gettimeofday __SYS_gettimeofday
#else
#    define SYS_gettimeofday __MISC
#endif

#if defined(__SYS_getrlimit)
#    define SYS_getrlimit __SYS_getrlimit
#else
#    define SYS_getrlimit __MISC
#endif

#if defined(__SYS_getrusage)
#    define SYS_getrusage __SYS_getrusage
#else
#    define SYS_getrusage __MISC
#endif

#if defined(__SYS_sysinfo)
#    define SYS_sysinfo __SYS_sysinfo
#else
#    define SYS_sysinfo __MISC
#endif

#if defined(__SYS_times)
#    define SYS_times __SYS_times
#else
#    define SYS_times __MISC
#endif

#if defined(__SYS_ptrace)
#    define SYS_ptrace __SYS_ptrace
#else
#    define SYS_ptrace __MISC
#endif

#if defined(__SYS_getuid)
#    define SYS_getuid __SYS_getuid
#else
#    define SYS_getuid __MISC
#endif

#if defined(__SYS_syslog)
#    define SYS_syslog __SYS_syslog
#else
#    define SYS_syslog __MISC
#endif

#if defined(__SYS_getgid)
#    define SYS_getgid __SYS_getgid
#else
#    define SYS_getgid __MISC
#endif

#if defined(__SYS_setuid)
#    define SYS_setuid __SYS_setuid
#else
#    define SYS_setuid __MISC
#endif

#if defined(__SYS_setgid)
#    define SYS_setgid __SYS_setgid
#else
#    define SYS_setgid __MISC
#endif

#if defined(__SYS_geteuid)
#    define SYS_geteuid __SYS_geteuid
#else
#    define SYS_geteuid __MISC
#endif

#if defined(__SYS_getegid)
#    define SYS_getegid __SYS_getegid
#else
#    define SYS_getegid __MISC
#endif

#if defined(__SYS_setpgid)
#    define SYS_setpgid __SYS_setpgid
#else
#    define SYS_setpgid __MISC
#endif

#if defined(__SYS_getppid)
#    define SYS_getppid __SYS_getppid
#else
#    define SYS_getppid __MISC
#endif

#if defined(__SYS_getpgrp)
#    define SYS_getpgrp __SYS_getpgrp
#else
#    define SYS_getpgrp __MISC
#endif

#if defined(__SYS_setsid)
#    define SYS_setsid __SYS_setsid
#else
#    define SYS_setsid __MISC
#endif

#if defined(__SYS_setreuid)
#    define SYS_setreuid __SYS_setreuid
#else
#    define SYS_setreuid __MISC
#endif

#if defined(__SYS_setregid)
#    define SYS_setregid __SYS_setregid
#else
#    define SYS_setregid __MISC
#endif

#if defined(__SYS_getgroups)
#    define SYS_getgroups __SYS_getgroups
#else
#    define SYS_getgroups __MISC
#endif

#if defined(__SYS_setgroups)
#    define SYS_setgroups __SYS_setgroups
#else
#    define SYS_setgroups __MISC
#endif

#if defined(__SYS_setresuid)
#    define SYS_setresuid __SYS_setresuid
#else
#    define SYS_setresuid __MISC
#endif

#if defined(__SYS_getresuid)
#    define SYS_getresuid __SYS_getresuid
#else
#    define SYS_getresuid __MISC
#endif

#if defined(__SYS_setresgid)
#    define SYS_setresgid __SYS_setresgid
#else
#    define SYS_setresgid __MISC
#endif

#if defined(__SYS_getresgid)
#    define SYS_getresgid __SYS_getresgid
#else
#    define SYS_getresgid __MISC
#endif

#if defined(__SYS_getpgid)
#    define SYS_getpgid __SYS_getpgid
#else
#    define SYS_getpgid __MISC
#endif

#if defined(__SYS_setfsuid)
#    define SYS_setfsuid __SYS_setfsuid
#else
#    define SYS_setfsuid __MISC
#endif

#if defined(__SYS_setfsgid)
#    define SYS_setfsgid __SYS_setfsgid
#else
#    define SYS_setfsgid __MISC
#endif

#if defined(__SYS_getsid)
#    define SYS_getsid __SYS_getsid
#else
#    define SYS_getsid __MISC
#endif

#if defined(__SYS_capget)
#    define SYS_capget __SYS_capget
#else
#    define SYS_capget __MISC
#endif

#if defined(__SYS_capset)
#    define SYS_capset __SYS_capset
#else
#    define SYS_capset __MISC
#endif

#if defined(__SYS_rt_sigpending)
#    define SYS_rt_sigpending __SYS_rt_sigpending
#else
#    define SYS_rt_sigpending __MISC
#endif

#if defined(__SYS_rt_sigtimedwait)
#    define SYS_rt_sigtimedwait __SYS_rt_sigtimedwait
#else
#    define SYS_rt_sigtimedwait __MISC
#endif

#if defined(__SYS_rt_sigqueueinfo)
#    define SYS_rt_sigqueueinfo __SYS_rt_sigqueueinfo
#else
#    define SYS_rt_sigqueueinfo __MISC
#endif

#if defined(__SYS_rt_sigsuspend)
#    define SYS_rt_sigsuspend __SYS_rt_sigsuspend
#else
#    define SYS_rt_sigsuspend __MISC
#endif

#if defined(__SYS_sigaltstack)
#    define SYS_sigaltstack __SYS_sigaltstack
#else
#    define SYS_sigaltstack __MISC
#endif

#if defined(__SYS_utime)
#    define SYS_utime __SYS_utime
#else
#    define SYS_utime __MISC
#endif

#if defined(__SYS_mknod)
#    define SYS_mknod __SYS_mknod
#else
#    define SYS_mknod __MISC
#endif

#if defined(__SYS_uselib)
#    define SYS_uselib __SYS_uselib
#else
#    define SYS_uselib __MISC
#endif

#if defined(__SYS_personality)
#    define SYS_personality __SYS_personality
#else
#    define SYS_personality __MISC
#endif

#if defined(__SYS_ustat)
#    define SYS_ustat __SYS_ustat
#else
#    define SYS_ustat __MISC
#endif

#if defined(__SYS_statfs)
#    define SYS_statfs __SYS_statfs
#else
#    define SYS_statfs __MISC
#endif

#if defined(__SYS_fstatfs)
#    define SYS_fstatfs __SYS_fstatfs
#else
#    define SYS_fstatfs __MISC
#endif

#if defined(__SYS_sysfs)
#    define SYS_sysfs __SYS_sysfs
#else
#    define SYS_sysfs __MISC
#endif

#if defined(__SYS_getpriority)
#    define SYS_getpriority __SYS_getpriority
#else
#    define SYS_getpriority __MISC
#endif

#if defined(__SYS_setpriority)
#    define SYS_setpriority __SYS_setpriority
#else
#    define SYS_setpriority __MISC
#endif

#if defined(__SYS_sched_setparam)
#    define SYS_sched_setparam __SYS_sched_setparam
#else
#    define SYS_sched_setparam __MISC
#endif

#if defined(__SYS_sched_getparam)
#    define SYS_sched_getparam __SYS_sched_getparam
#else
#    define SYS_sched_getparam __MISC
#endif

#if defined(__SYS_sched_setscheduler)
#    define SYS_sched_setscheduler __SYS_sched_setscheduler
#else
#    define SYS_sched_setscheduler __MISC
#endif

#if defined(__SYS_sched_getscheduler)
#    define SYS_sched_getscheduler __SYS_sched_getscheduler
#else
#    define SYS_sched_getscheduler __MISC
#endif

#if defined(__SYS_sched_get_priority_max)
#    define SYS_sched_get_priority_max __SYS_sched_get_priority_max
#else
#    define SYS_sched_get_priority_max __MISC
#endif

#if defined(__SYS_sched_get_priority_min)
#    define SYS_sched_get_priority_min __SYS_sched_get_priority_min
#else
#    define SYS_sched_get_priority_min __MISC
#endif

#if defined(__SYS_sched_rr_get_interval)
#    define SYS_sched_rr_get_interval __SYS_sched_rr_get_interval
#else
#    define SYS_sched_rr_get_interval __MISC
#endif

#if defined(__SYS_mlock)
#    define SYS_mlock __SYS_mlock
#else
#    define SYS_mlock __MISC
#endif

#if defined(__SYS_munlock)
#    define SYS_munlock __SYS_munlock
#else
#    define SYS_munlock __MISC
#endif

#if defined(__SYS_mlockall)
#    define SYS_mlockall __SYS_mlockall
#else
#    define SYS_mlockall __MISC
#endif

#if defined(__SYS_munlockall)
#    define SYS_munlockall __SYS_munlockall
#else
#    define SYS_munlockall __MISC
#endif

#if defined(__SYS_vhangup)
#    define SYS_vhangup __SYS_vhangup
#else
#    define SYS_vhangup __MISC
#endif

#if defined(__SYS_modify_ldt)
#    define SYS_modify_ldt __SYS_modify_ldt
#else
#    define SYS_modify_ldt __MISC
#endif

#if defined(__SYS_pivot_root)
#    define SYS_pivot_root __SYS_pivot_root
#else
#    define SYS_pivot_root __MISC
#endif

#if defined(__SYS__sysctl)
#    define SYS__sysctl __SYS__sysctl
#else
#    define SYS__sysctl __MISC
#endif

#if defined(__SYS_prctl)
#    define SYS_prctl __SYS_prctl
#else
#    define SYS_prctl __MISC
#endif

#if defined(__SYS_arch_prctl)
#    define SYS_arch_prctl __SYS_arch_prctl
#else
#    define SYS_arch_prctl __MISC
#endif

#if defined(__SYS_adjtimex)
#    define SYS_adjtimex __SYS_adjtimex
#else
#    define SYS_adjtimex __MISC
#endif

#if defined(__SYS_setrlimit)
#    define SYS_setrlimit __SYS_setrlimit
#else
#    define SYS_setrlimit __MISC
#endif

#if defined(__SYS_chroot)
#    define SYS_chroot __SYS_chroot
#else
#    define SYS_chroot __MISC
#endif

#if defined(__SYS_sync)
#    define SYS_sync __SYS_sync
#else
#    define SYS_sync __MISC
#endif

#if defined(__SYS_acct)
#    define SYS_acct __SYS_acct
#else
#    define SYS_acct __MISC
#endif

#if defined(__SYS_settimeofday)
#    define SYS_settimeofday __SYS_settimeofday
#else
#    define SYS_settimeofday __MISC
#endif

#if defined(__SYS_mount)
#    define SYS_mount __SYS_mount
#else
#    define SYS_mount __MISC
#endif

#if defined(__SYS_umount2)
#    define SYS_umount2 __SYS_umount2
#else
#    define SYS_umount2 __MISC
#endif

#if defined(__SYS_swapon)
#    define SYS_swapon __SYS_swapon
#else
#    define SYS_swapon __MISC
#endif

#if defined(__SYS_swapoff)
#    define SYS_swapoff __SYS_swapoff
#else
#    define SYS_swapoff __MISC
#endif

#if defined(__SYS_reboot)
#    define SYS_reboot __SYS_reboot
#else
#    define SYS_reboot __MISC
#endif

#if defined(__SYS_sethostname)
#    define SYS_sethostname __SYS_sethostname
#else
#    define SYS_sethostname __MISC
#endif

#if defined(__SYS_setdomainname)
#    define SYS_setdomainname __SYS_setdomainname
#else
#    define SYS_setdomainname __MISC
#endif

#if defined(__SYS_iopl)
#    define SYS_iopl __SYS_iopl
#else
#    define SYS_iopl __MISC
#endif

#if defined(__SYS_ioperm)
#    define SYS_ioperm __SYS_ioperm
#else
#    define SYS_ioperm __MISC
#endif

#if defined(__SYS_create_module)
#    define SYS_create_module __SYS_create_module
#else
#    define SYS_create_module __MISC
#endif

#if defined(__SYS_init_module)
#    define SYS_init_module __SYS_init_module
#else
#    define SYS_init_module __MISC
#endif

#if defined(__SYS_delete_module)
#    define SYS_delete_module __SYS_delete_module
#else
#    define SYS_delete_module __MISC
#endif

#if defined(__SYS_get_kernel_syms)
#    define SYS_get_kernel_syms __SYS_get_kernel_syms
#else
#    define SYS_get_kernel_syms __MISC
#endif

#if defined(__SYS_query_module)
#    define SYS_query_module __SYS_query_module
#else
#    define SYS_query_module __MISC
#endif

#if defined(__SYS_quotactl)
#    define SYS_quotactl __SYS_quotactl
#else
#    define SYS_quotactl __MISC
#endif

#if defined(__SYS_nfsservctl)
#    define SYS_nfsservctl __SYS_nfsservctl
#else
#    define SYS_nfsservctl __MISC
#endif

#if defined(__SYS_getpmsg)
#    define SYS_getpmsg __SYS_getpmsg
#else
#    define SYS_getpmsg __MISC
#endif

#if defined(__SYS_putpmsg)
#    define SYS_putpmsg __SYS_putpmsg
#else
#    define SYS_putpmsg __MISC
#endif

#if defined(__SYS_afs_syscall)
#    define SYS_afs_syscall __SYS_afs_syscall
#else
#    define SYS_afs_syscall __MISC
#endif

#if defined(__SYS_tuxcall)
#    define SYS_tuxcall __SYS_tuxcall
#else
#    define SYS_tuxcall __MISC
#endif

#if defined(__SYS_security)
#    define SYS_security __SYS_security
#else
#    define SYS_security __MISC
#endif

#if defined(__SYS_gettid)
#    define SYS_gettid __SYS_gettid
#else
#    define SYS_gettid __MISC
#endif

#if defined(__SYS_readahead)
#    define SYS_readahead __SYS_readahead
#else
#    define SYS_readahead __MISC
#endif

#if defined(__SYS_setxattr)
#    define SYS_setxattr __SYS_setxattr
#else
#    define SYS_setxattr __MISC
#endif

#if defined(__SYS_lsetxattr)
#    define SYS_lsetxattr __SYS_lsetxattr
#else
#    define SYS_lsetxattr __MISC
#endif

#if defined(__SYS_fsetxattr)
#    define SYS_fsetxattr __SYS_fsetxattr
#else
#    define SYS_fsetxattr __MISC
#endif

#if defined(__SYS_getxattr)
#    define SYS_getxattr __SYS_getxattr
#else
#    define SYS_getxattr __MISC
#endif

#if defined(__SYS_lgetxattr)
#    define SYS_lgetxattr __SYS_lgetxattr
#else
#    define SYS_lgetxattr __MISC
#endif

#if defined(__SYS_fgetxattr)
#    define SYS_fgetxattr __SYS_fgetxattr
#else
#    define SYS_fgetxattr __MISC
#endif

#if defined(__SYS_listxattr)
#    define SYS_listxattr __SYS_listxattr
#else
#    define SYS_listxattr __MISC
#endif

#if defined(__SYS_llistxattr)
#    define SYS_llistxattr __SYS_llistxattr
#else
#    define SYS_llistxattr __MISC
#endif

#if defined(__SYS_flistxattr)
#    define SYS_flistxattr __SYS_flistxattr
#else
#    define SYS_flistxattr __MISC
#endif

#if defined(__SYS_removexattr)
#    define SYS_removexattr __SYS_removexattr
#else
#    define SYS_removexattr __MISC
#endif

#if defined(__SYS_lremovexattr)
#    define SYS_lremovexattr __SYS_lremovexattr
#else
#    define SYS_lremovexattr __MISC
#endif

#if defined(__SYS_fremovexattr)
#    define SYS_fremovexattr __SYS_fremovexattr
#else
#    define SYS_fremovexattr __MISC
#endif

#if defined(__SYS_tkill)
#    define SYS_tkill __SYS_tkill
#else
#    define SYS_tkill __MISC
#endif

#if defined(__SYS_time)
#    define SYS_time __SYS_time
#else
#    define SYS_time __MISC
#endif

#if defined(__SYS_futex)
#    define SYS_futex __SYS_futex
#else
#    define SYS_futex __MISC
#endif

#if defined(__SYS_sched_setaffinity)
#    define SYS_sched_setaffinity __SYS_sched_setaffinity
#else
#    define SYS_sched_setaffinity __MISC
#endif

#if defined(__SYS_sched_getaffinity)
#    define SYS_sched_getaffinity __SYS_sched_getaffinity
#else
#    define SYS_sched_getaffinity __MISC
#endif

#if defined(__SYS_set_thread_area)
#    define SYS_set_thread_area __SYS_set_thread_area
#else
#    define SYS_set_thread_area __MISC
#endif

#if defined(__SYS_io_setup)
#    define SYS_io_setup __SYS_io_setup
#else
#    define SYS_io_setup __MISC
#endif

#if defined(__SYS_io_destroy)
#    define SYS_io_destroy __SYS_io_destroy
#else
#    define SYS_io_destroy __MISC
#endif

#if defined(__SYS_io_getevents)
#    define SYS_io_getevents __SYS_io_getevents
#else
#    define SYS_io_getevents __MISC
#endif

#if defined(__SYS_io_submit)
#    define SYS_io_submit __SYS_io_submit
#else
#    define SYS_io_submit __MISC
#endif

#if defined(__SYS_io_cancel)
#    define SYS_io_cancel __SYS_io_cancel
#else
#    define SYS_io_cancel __MISC
#endif

#if defined(__SYS_get_thread_area)
#    define SYS_get_thread_area __SYS_get_thread_area
#else
#    define SYS_get_thread_area __MISC
#endif

#if defined(__SYS_lookup_dcookie)
#    define SYS_lookup_dcookie __SYS_lookup_dcookie
#else
#    define SYS_lookup_dcookie __MISC
#endif

#if defined(__SYS_epoll_create)
#    define SYS_epoll_create __SYS_epoll_create
#else
#    define SYS_epoll_create __MISC
#endif

#if defined(__SYS_epoll_ctl_old)
#    define SYS_epoll_ctl_old __SYS_epoll_ctl_old
#else
#    define SYS_epoll_ctl_old __MISC
#endif

#if defined(__SYS_epoll_wait_old)
#    define SYS_epoll_wait_old __SYS_epoll_wait_old
#else
#    define SYS_epoll_wait_old __MISC
#endif

#if defined(__SYS_remap_file_pages)
#    define SYS_remap_file_pages __SYS_remap_file_pages
#else
#    define SYS_remap_file_pages __MISC
#endif

#if defined(__SYS_getdents64)
#    define SYS_getdents64 __SYS_getdents64
#else
#    define SYS_getdents64 __MISC
#endif

#if defined(__SYS_set_tid_address)
#    define SYS_set_tid_address __SYS_set_tid_address
#else
#    define SYS_set_tid_address __MISC
#endif

#if defined(__SYS_restart_syscall)
#    define SYS_restart_syscall __SYS_restart_syscall
#else
#    define SYS_restart_syscall __MISC
#endif

#if defined(__SYS_semtimedop)
#    define SYS_semtimedop __SYS_semtimedop
#else
#    define SYS_semtimedop __MISC
#endif

#if defined(__SYS_fadvise64)
#    define SYS_fadvise64 __SYS_fadvise64
#else
#    define SYS_fadvise64 __MISC
#endif

#if defined(__SYS_timer_create)
#    define SYS_timer_create __SYS_timer_create
#else
#    define SYS_timer_create __MISC
#endif

#if defined(__SYS_timer_settime)
#    define SYS_timer_settime __SYS_timer_settime
#else
#    define SYS_timer_settime __MISC
#endif

#if defined(__SYS_timer_gettime)
#    define SYS_timer_gettime __SYS_timer_gettime
#else
#    define SYS_timer_gettime __MISC
#endif

#if defined(__SYS_timer_getoverrun)
#    define SYS_timer_getoverrun __SYS_timer_getoverrun
#else
#    define SYS_timer_getoverrun __MISC
#endif

#if defined(__SYS_timer_delete)
#    define SYS_timer_delete __SYS_timer_delete
#else
#    define SYS_timer_delete __MISC
#endif

#if defined(__SYS_clock_settime)
#    define SYS_clock_settime __SYS_clock_settime
#else
#    define SYS_clock_settime __MISC
#endif

#if defined(__SYS_clock_gettime)
#    define SYS_clock_gettime __SYS_clock_gettime
#else
#    define SYS_clock_gettime __MISC
#endif

#if defined(__SYS_clock_getres)
#    define SYS_clock_getres __SYS_clock_getres
#else
#    define SYS_clock_getres __MISC
#endif

#if defined(__SYS_clock_nanosleep)
#    define SYS_clock_nanosleep __SYS_clock_nanosleep
#else
#    define SYS_clock_nanosleep __MISC
#endif

#if defined(__SYS_exit_group)
#    define SYS_exit_group __SYS_exit_group
#else
#    define SYS_exit_group __MISC
#endif

#if defined(__SYS_epoll_wait)
#    define SYS_epoll_wait __SYS_epoll_wait
#else
#    define SYS_epoll_wait __MISC
#endif

#if defined(__SYS_epoll_ctl)
#    define SYS_epoll_ctl __SYS_epoll_ctl
#else
#    define SYS_epoll_ctl __MISC
#endif

#if defined(__SYS_tgkill)
#    define SYS_tgkill __SYS_tgkill
#else
#    define SYS_tgkill __MISC
#endif

#if defined(__SYS_utimes)
#    define SYS_utimes __SYS_utimes
#else
#    define SYS_utimes __MISC
#endif

#if defined(__SYS_vserver)
#    define SYS_vserver __SYS_vserver
#else
#    define SYS_vserver __MISC
#endif

#if defined(__SYS_mbind)
#    define SYS_mbind __SYS_mbind
#else
#    define SYS_mbind __MISC
#endif

#if defined(__SYS_set_mempolicy)
#    define SYS_set_mempolicy __SYS_set_mempolicy
#else
#    define SYS_set_mempolicy __MISC
#endif

#if defined(__SYS_get_mempolicy)
#    define SYS_get_mempolicy __SYS_get_mempolicy
#else
#    define SYS_get_mempolicy __MISC
#endif

#if defined(__SYS_mq_open)
#    define SYS_mq_open __SYS_mq_open
#else
#    define SYS_mq_open __MISC
#endif

#if defined(__SYS_mq_unlink)
#    define SYS_mq_unlink __SYS_mq_unlink
#else
#    define SYS_mq_unlink __MISC
#endif

#if defined(__SYS_mq_timedsend)
#    define SYS_mq_timedsend __SYS_mq_timedsend
#else
#    define SYS_mq_timedsend __MISC
#endif

#if defined(__SYS_mq_timedreceive)
#    define SYS_mq_timedreceive __SYS_mq_timedreceive
#else
#    define SYS_mq_timedreceive __MISC
#endif

#if defined(__SYS_mq_notify)
#    define SYS_mq_notify __SYS_mq_notify
#else
#    define SYS_mq_notify __MISC
#endif

#if defined(__SYS_mq_getsetattr)
#    define SYS_mq_getsetattr __SYS_mq_getsetattr
#else
#    define SYS_mq_getsetattr __MISC
#endif

#if defined(__SYS_kexec_load)
#    define SYS_kexec_load __SYS_kexec_load
#else
#    define SYS_kexec_load __MISC
#endif

#if defined(__SYS_waitid)
#    define SYS_waitid __SYS_waitid
#else
#    define SYS_waitid __MISC
#endif

#if defined(__SYS_add_key)
#    define SYS_add_key __SYS_add_key
#else
#    define SYS_add_key __MISC
#endif

#if defined(__SYS_request_key)
#    define SYS_request_key __SYS_request_key
#else
#    define SYS_request_key __MISC
#endif

#if defined(__SYS_keyctl)
#    define SYS_keyctl __SYS_keyctl
#else
#    define SYS_keyctl __MISC
#endif

#if defined(__SYS_ioprio_set)
#    define SYS_ioprio_set __SYS_ioprio_set
#else
#    define SYS_ioprio_set __MISC
#endif

#if defined(__SYS_ioprio_get)
#    define SYS_ioprio_get __SYS_ioprio_get
#else
#    define SYS_ioprio_get __MISC
#endif

#if defined(__SYS_inotify_init)
#    define SYS_inotify_init __SYS_inotify_init
#else
#    define SYS_inotify_init __MISC
#endif

#if defined(__SYS_inotify_add_watch)
#    define SYS_inotify_add_watch __SYS_inotify_add_watch
#else
#    define SYS_inotify_add_watch __MISC
#endif

#if defined(__SYS_inotify_rm_watch)
#    define SYS_inotify_rm_watch __SYS_inotify_rm_watch
#else
#    define SYS_inotify_rm_watch __MISC
#endif

#if defined(__SYS_migrate_pages)
#    define SYS_migrate_pages __SYS_migrate_pages
#else
#    define SYS_migrate_pages __MISC
#endif

#if defined(__SYS_openat)
#    define SYS_openat __SYS_openat
#else
#    define SYS_openat __MISC
#endif

#if defined(__SYS_mkdirat)
#    define SYS_mkdirat __SYS_mkdirat
#else
#    define SYS_mkdirat __MISC
#endif

#if defined(__SYS_mknodat)
#    define SYS_mknodat __SYS_mknodat
#else
#    define SYS_mknodat __MISC
#endif

#if defined(__SYS_fchownat)
#    define SYS_fchownat __SYS_fchownat
#else
#    define SYS_fchownat __MISC
#endif

#if defined(__SYS_futimesat)
#    define SYS_futimesat __SYS_futimesat
#else
#    define SYS_futimesat __MISC
#endif

#if defined(__SYS_newfstatat)
#    define SYS_newfstatat __SYS_newfstatat
#else
#    define SYS_newfstatat __MISC
#endif

#if defined(__SYS_unlinkat)
#    define SYS_unlinkat __SYS_unlinkat
#else
#    define SYS_unlinkat __MISC
#endif

#if defined(__SYS_renameat)
#    define SYS_renameat __SYS_renameat
#else
#    define SYS_renameat __MISC
#endif

#if defined(__SYS_linkat)
#    define SYS_linkat __SYS_linkat
#else
#    define SYS_linkat __MISC
#endif

#if defined(__SYS_symlinkat)
#    define SYS_symlinkat __SYS_symlinkat
#else
#    define SYS_symlinkat __MISC
#endif

#if defined(__SYS_readlinkat)
#    define SYS_readlinkat __SYS_readlinkat
#else
#    define SYS_readlinkat __MISC
#endif

#if defined(__SYS_fchmodat)
#    define SYS_fchmodat __SYS_fchmodat
#else
#    define SYS_fchmodat __MISC
#endif

#if defined(__SYS_faccessat)
#    define SYS_faccessat __SYS_faccessat
#else
#    define SYS_faccessat __MISC
#endif

#if defined(__SYS_pselect6)
#    define SYS_pselect6 __SYS_pselect6
#else
#    define SYS_pselect6 __MISC
#endif

#if defined(__SYS_ppoll)
#    define SYS_ppoll __SYS_ppoll
#else
#    define SYS_ppoll __MISC
#endif

#if defined(__SYS_unshare)
#    define SYS_unshare __SYS_unshare
#else
#    define SYS_unshare __MISC
#endif

#if defined(__SYS_set_robust_list)
#    define SYS_set_robust_list __SYS_set_robust_list
#else
#    define SYS_set_robust_list __MISC
#endif

#if defined(__SYS_get_robust_list)
#    define SYS_get_robust_list __SYS_get_robust_list
#else
#    define SYS_get_robust_list __MISC
#endif

#if defined(__SYS_splice)
#    define SYS_splice __SYS_splice
#else
#    define SYS_splice __MISC
#endif

#if defined(__SYS_tee)
#    define SYS_tee __SYS_tee
#else
#    define SYS_tee __MISC
#endif

#if defined(__SYS_sync_file_range)
#    define SYS_sync_file_range __SYS_sync_file_range
#else
#    define SYS_sync_file_range __MISC
#endif

#if defined(__SYS_vmsplice)
#    define SYS_vmsplice __SYS_vmsplice
#else
#    define SYS_vmsplice __MISC
#endif

#if defined(__SYS_move_pages)
#    define SYS_move_pages __SYS_move_pages
#else
#    define SYS_move_pages __MISC
#endif

#if defined(__SYS_utimensat)
#    define SYS_utimensat __SYS_utimensat
#else
#    define SYS_utimensat __MISC
#endif

#if defined(__SYS_epoll_pwait)
#    define SYS_epoll_pwait __SYS_epoll_pwait
#else
#    define SYS_epoll_pwait __MISC
#endif

#if defined(__SYS_signalfd)
#    define SYS_signalfd __SYS_signalfd
#else
#    define SYS_signalfd __MISC
#endif

#if defined(__SYS_timerfd_create)
#    define SYS_timerfd_create __SYS_timerfd_create
#else
#    define SYS_timerfd_create __MISC
#endif

#if defined(__SYS_eventfd)
#    define SYS_eventfd __SYS_eventfd
#else
#    define SYS_eventfd __MISC
#endif

#if defined(__SYS_fallocate)
#    define SYS_fallocate __SYS_fallocate
#else
#    define SYS_fallocate __MISC
#endif

#if defined(__SYS_timerfd_settime)
#    define SYS_timerfd_settime __SYS_timerfd_settime
#else
#    define SYS_timerfd_settime __MISC
#endif

#if defined(__SYS_timerfd_gettime)
#    define SYS_timerfd_gettime __SYS_timerfd_gettime
#else
#    define SYS_timerfd_gettime __MISC
#endif

#if defined(__SYS_accept4)
#    define SYS_accept4 __SYS_accept4
#else
#    define SYS_accept4 __MISC
#endif

#if defined(__SYS_signalfd4)
#    define SYS_signalfd4 __SYS_signalfd4
#else
#    define SYS_signalfd4 __MISC
#endif

#if defined(__SYS_eventfd2)
#    define SYS_eventfd2 __SYS_eventfd2
#else
#    define SYS_eventfd2 __MISC
#endif

#if defined(__SYS_epoll_create1)
#    define SYS_epoll_create1 __SYS_epoll_create1
#else
#    define SYS_epoll_create1 __MISC
#endif

#if defined(__SYS_dup3)
#    define SYS_dup3 __SYS_dup3
#else
#    define SYS_dup3 __MISC
#endif

#if defined(__SYS_pipe2)
#    define SYS_pipe2 __SYS_pipe2
#else
#    define SYS_pipe2 __MISC
#endif

#if defined(__SYS_inotify_init1)
#    define SYS_inotify_init1 __SYS_inotify_init1
#else
#    define SYS_inotify_init1 __MISC
#endif

#if defined(__SYS_preadv)
#    define SYS_preadv __SYS_preadv
#else
#    define SYS_preadv __MISC
#endif

#if defined(__SYS_pwritev)
#    define SYS_pwritev __SYS_pwritev
#else
#    define SYS_pwritev __MISC
#endif

#if defined(__SYS_rt_tgsigqueueinfo)
#    define SYS_rt_tgsigqueueinfo __SYS_rt_tgsigqueueinfo
#else
#    define SYS_rt_tgsigqueueinfo __MISC
#endif

#if defined(__SYS_perf_event_open)
#    define SYS_perf_event_open __SYS_perf_event_open
#else
#    define SYS_perf_event_open __MISC
#endif

#if defined(__SYS_recvmmsg)
#    define SYS_recvmmsg __SYS_recvmmsg
#else
#    define SYS_recvmmsg __MISC
#endif

#if defined(__SYS_fanotify_init)
#    define SYS_fanotify_init __SYS_fanotify_init
#else
#    define SYS_fanotify_init __MISC
#endif

#if defined(__SYS_fanotify_mark)
#    define SYS_fanotify_mark __SYS_fanotify_mark
#else
#    define SYS_fanotify_mark __MISC
#endif

#if defined(__SYS_prlimit64)
#    define SYS_prlimit64 __SYS_prlimit64
#else
#    define SYS_prlimit64 __MISC
#endif

#if defined(__SYS_name_to_handle_at)
#    define SYS_name_to_handle_at __SYS_name_to_handle_at
#else
#    define SYS_name_to_handle_at __MISC
#endif

#if defined(__SYS_open_by_handle_at)
#    define SYS_open_by_handle_at __SYS_open_by_handle_at
#else
#    define SYS_open_by_handle_at __MISC
#endif

#if defined(__SYS_clock_adjtime)
#    define SYS_clock_adjtime __SYS_clock_adjtime
#else
#    define SYS_clock_adjtime __MISC
#endif

#if defined(__SYS_syncfs)
#    define SYS_syncfs __SYS_syncfs
#else
#    define SYS_syncfs __MISC
#endif

#if defined(__SYS_sendmmsg)
#    define SYS_sendmmsg __SYS_sendmmsg
#else
#    define SYS_sendmmsg __MISC
#endif

#if defined(__SYS_setns)
#    define SYS_setns __SYS_setns
#else
#    define SYS_setns __MISC
#endif

#if defined(__SYS_getcpu)
#    define SYS_getcpu __SYS_getcpu
#else
#    define SYS_getcpu __MISC
#endif

#if defined(__SYS_process_vm_readv)
#    define SYS_process_vm_readv __SYS_process_vm_readv
#else
#    define SYS_process_vm_readv __MISC
#endif

#if defined(__SYS_process_vm_writev)
#    define SYS_process_vm_writev __SYS_process_vm_writev
#else
#    define SYS_process_vm_writev __MISC
#endif

#if defined(__SYS_kcmp)
#    define SYS_kcmp __SYS_kcmp
#else
#    define SYS_kcmp __MISC
#endif

#if defined(__SYS_finit_module)
#    define SYS_finit_module __SYS_finit_module
#else
#    define SYS_finit_module __MISC
#endif

#if defined(__SYS_sched_setattr)
#    define SYS_sched_setattr __SYS_sched_setattr
#else
#    define SYS_sched_setattr __MISC
#endif

#if defined(__SYS_sched_getattr)
#    define SYS_sched_getattr __SYS_sched_getattr
#else
#    define SYS_sched_getattr __MISC
#endif

#if defined(__SYS_renameat2)
#    define SYS_renameat2 __SYS_renameat2
#else
#    define SYS_renameat2 __MISC
#endif

#if defined(__SYS_seccomp)
#    define SYS_seccomp __SYS_seccomp
#else
#    define SYS_seccomp __MISC
#endif

#if defined(__SYS_getrandom)
#    define SYS_getrandom __SYS_getrandom
#else
#    define SYS_getrandom __MISC
#endif

#if defined(__SYS_memfd_create)
#    define SYS_memfd_create __SYS_memfd_create
#else
#    define SYS_memfd_create __MISC
#endif

#if defined(__SYS_kexec_file_load)
#    define SYS_kexec_file_load __SYS_kexec_file_load
#else
#    define SYS_kexec_file_load __MISC
#endif

#if defined(__SYS_bpf)
#    define SYS_bpf __SYS_bpf
#else
#    define SYS_bpf __MISC
#endif

#if defined(__SYS_execveat)
#    define SYS_execveat __SYS_execveat
#else
#    define SYS_execveat __MISC
#endif

#if defined(__SYS_userfaultfd)
#    define SYS_userfaultfd __SYS_userfaultfd
#else
#    define SYS_userfaultfd __MISC
#endif

#if defined(__SYS_membarrier)
#    define SYS_membarrier __SYS_membarrier
#else
#    define SYS_membarrier __MISC
#endif

#if defined(__SYS_mlock2)
#    define SYS_mlock2 __SYS_mlock2
#else
#    define SYS_mlock2 __MISC
#endif

#if defined(__SYS_copy_file_range)
#    define SYS_copy_file_range __SYS_copy_file_range
#else
#    define SYS_copy_file_range __MISC
#endif

#if defined(__SYS_preadv2)
#    define SYS_preadv2 __SYS_preadv2
#else
#    define SYS_preadv2 __MISC
#endif

#if defined(__SYS_pwritev2)
#    define SYS_pwritev2 __SYS_pwritev2
#else
#    define SYS_pwritev2 __MISC
#endif

#if defined(__SYS_pkey_mprotect)
#    define SYS_pkey_mprotect __SYS_pkey_mprotect
#else
#    define SYS_pkey_mprotect __MISC
#endif

#if defined(__SYS_pkey_alloc)
#    define SYS_pkey_alloc __SYS_pkey_alloc
#else
#    define SYS_pkey_alloc __MISC
#endif

#if defined(__SYS_pkey_free)
#    define SYS_pkey_free __SYS_pkey_free
#else
#    define SYS_pkey_free __MISC
#endif

#if defined(__SYS_statx)
#    define SYS_statx __SYS_statx
#else
#    define SYS_statx __MISC
#endif

#if defined(__SYS_io_pgetevents)
#    define SYS_io_pgetevents __SYS_io_pgetevents
#else
#    define SYS_io_pgetevents __MISC
#endif

#if defined(__SYS_rseq)
#    define SYS_rseq __SYS_rseq
#else
#    define SYS_rseq __MISC
#endif

#if defined(__SYS_pidfd_send_signal)
#    define SYS_pidfd_send_signal __SYS_pidfd_send_signal
#else
#    define SYS_pidfd_send_signal __MISC
#endif

#if defined(__SYS_io_uring_setup)
#    define SYS_io_uring_setup __SYS_io_uring_setup
#else
#    define SYS_io_uring_setup __MISC
#endif

#if defined(__SYS_io_uring_enter)
#    define SYS_io_uring_enter __SYS_io_uring_enter
#else
#    define SYS_io_uring_enter __MISC
#endif

#if defined(__SYS_io_uring_register)
#    define SYS_io_uring_register __SYS_io_uring_register
#else
#    define SYS_io_uring_register __MISC
#endif

#if defined(__SYS_open_tree)
#    define SYS_open_tree __SYS_open_tree
#else
#    define SYS_open_tree __MISC
#endif

#if defined(__SYS_move_mount)
#    define SYS_move_mount __SYS_move_mount
#else
#    define SYS_move_mount __MISC
#endif

#if defined(__SYS_fsopen)
#    define SYS_fsopen __SYS_fsopen
#else
#    define SYS_fsopen __MISC
#endif

#if defined(__SYS_fsconfig)
#    define SYS_fsconfig __SYS_fsconfig
#else
#    define SYS_fsconfig __MISC
#endif

#if defined(__SYS_fsmount)
#    define SYS_fsmount __SYS_fsmount
#else
#    define SYS_fsmount __MISC
#endif

#if defined(__SYS_fspick)
#    define SYS_fspick __SYS_fspick
#else
#    define SYS_fspick __MISC
#endif

#if defined(__SYS_pidfd_open)
#    define SYS_pidfd_open __SYS_pidfd_open
#else
#    define SYS_pidfd_open __MISC
#endif

#if defined(__SYS_clone3)
#    define SYS_clone3 __SYS_clone3
#else
#    define SYS_clone3 __MISC
#endif

#if defined(__SYS_close_range)
#    define SYS_close_range __SYS_close_range
#else
#    define SYS_close_range __MISC
#endif

#if defined(__SYS_openat2)
#    define SYS_openat2 __SYS_openat2
#else
#    define SYS_openat2 __MISC
#endif

#if defined(__SYS_pidfd_getfd)
#    define SYS_pidfd_getfd __SYS_pidfd_getfd
#else
#    define SYS_pidfd_getfd __MISC
#endif

#if defined(__SYS_faccessat2)
#    define SYS_faccessat2 __SYS_faccessat2
#else
#    define SYS_faccessat2 __MISC
#endif

#if defined(__SYS_process_madvise)
#    define SYS_process_madvise __SYS_process_madvise
#else
#    define SYS_process_madvise __MISC
#endif

#endif /* __SYSCALL_H__ */
