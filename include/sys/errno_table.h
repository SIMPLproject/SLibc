#ifndef __ERRNO_TABLE_H__
#define __ERRNO_TABLE_H__

// default errno table
// arch specific will be in sysdeps/ARCH../errno_table.h
// this will overwrite the default
#if __has_include(<asm/errno_table.h>)

#include <asm/errno_table.h>

#endif

#ifndef EPERM
#define EPERM 1
#endif

#ifndef ENOENT
#define ENOENT 2
#endif

#ifndef ESRCH
#define ESRCH 3
#endif

#ifndef EINTR
#define EINTR 4
#endif

#ifndef EIO
#define EIO 5
#endif

#ifndef ENXIO
#define ENXIO 6
#endif

#ifndef E2BIG
#define E2BIG 7
#endif

#ifndef ENOEXEC
#define ENOEXEC 8
#endif

#ifndef EBADF
#define EBADF 9
#endif

#ifndef ECHILD
#define ECHILD 10
#endif

#ifndef EAGAIN
#define EAGAIN 11
#endif

#ifndef ENOMEM
#define ENOMEM 12
#endif

#ifndef EACCES
#define EACCES 13
#endif

#ifndef EFAULT
#define EFAULT 14
#endif

#ifndef ENOTBLK
#define ENOTBLK 15
#endif

#ifndef EBUSY
#define EBUSY 16
#endif

#ifndef EEXIST
#define EEXIST 17
#endif

#ifndef EXDEV
#define EXDEV 18
#endif

#ifndef ENODEV
#define ENODEV 19
#endif

#ifndef ENOTDIR
#define ENOTDIR 20
#endif

#ifndef EISDIR
#define EISDIR 21
#endif

#ifndef EINVAL
#define EINVAL 22
#endif

#ifndef ENFILE
#define ENFILE 23
#endif

#ifndef EMFILE
#define EMFILE 24
#endif

#ifndef ENOTTY
#define ENOTTY 25
#endif

#ifndef ETXTBSY
#define ETXTBSY 26
#endif

#ifndef EFBIG
#define EFBIG 27
#endif

#ifndef ENOSPC
#define ENOSPC 28
#endif

#ifndef ESPIPE
#define ESPIPE 29
#endif

#ifndef EROFS
#define EROFS 30
#endif

#ifndef EMLINK
#define EMLINK 31
#endif

#ifndef EPIPE
#define EPIPE 32
#endif

#ifndef EDOM
#define EDOM 33
#endif

#ifndef ERANGE
#define ERANGE 34
#endif

#ifndef ENOMSG
#define ENOMSG 35
#endif

#ifndef EIDRM
#define EIDRM 36
#endif

#ifndef ECHRNG
#define ECHRNG 37
#endif

#ifndef EL2NSYNC
#define EL2NSYNC 38
#endif

#ifndef EL3HLT
#define EL3HLT 39
#endif

#ifndef EL3RST
#define EL3RST 40
#endif

#ifndef ELNRNG
#define ELNRNG 41
#endif

#ifndef EUNATCH
#define EUNATCH 42
#endif

#ifndef ENOCSI
#define ENOCSI 43
#endif

#ifndef EL2HLT
#define EL2HLT 44
#endif

#ifndef EDEADLK
#define EDEADLK 45
#endif

#ifndef ENOLCK
#define ENOLCK 46
#endif

#ifndef EBADE
#define EBADE 50
#endif

#ifndef EBADR
#define EBADR 51
#endif

#ifndef EXFULL
#define EXFULL 52
#endif

#ifndef ENOANO
#define ENOANO 53
#endif

#ifndef EBADRQC
#define EBADRQC 54
#endif

#ifndef EBADSLT
#define EBADSLT 55
#endif

#ifndef EDEADLOCK
#define EDEADLOCK 56
#endif

#ifndef EBFONT
#define EBFONT 59
#endif

#ifndef ENOSTR
#define ENOSTR 60
#endif

#ifndef ENODATA
#define ENODATA 61
#endif

#ifndef ETIME
#define ETIME 62
#endif

#ifndef ENOSR
#define ENOSR 63
#endif

#ifndef ENONET
#define ENONET 64
#endif

#ifndef ENOPKG
#define ENOPKG 65
#endif

#ifndef EREMOTE
#define EREMOTE 66
#endif

#ifndef ENOLINK
#define ENOLINK 67
#endif

#ifndef EADV
#define EADV 68
#endif

#ifndef ESRMNT
#define ESRMNT 69
#endif

#ifndef ECOMM
#define ECOMM 70
#endif

#ifndef EPROTO
#define EPROTO 71
#endif

#ifndef EDOTDOT
#define EDOTDOT 73
#endif

#ifndef EMULTIHOP
#define EMULTIHOP 74
#endif

#ifndef EBADMSG
#define EBADMSG 77
#endif

#ifndef ENAMETOOLONG
#define ENAMETOOLONG 78
#endif

#ifndef EOVERFLOW
#define EOVERFLOW 79
#endif

#ifndef ENOTUNIQ
#define ENOTUNIQ 80
#endif

#ifndef EBADFD
#define EBADFD 81
#endif

#ifndef EREMCHG
#define EREMCHG 82
#endif

#ifndef ELIBACC
#define ELIBACC 83
#endif

#ifndef ELIBBAD
#define ELIBBAD 84
#endif

#ifndef ELIBSCN
#define ELIBSCN 85
#endif

#ifndef ELIBMAX
#define ELIBMAX 86
#endif

#ifndef ELIBEXEC
#define ELIBEXEC 87
#endif

#ifndef EILSEQ
#define EILSEQ 88
#endif

#ifndef ENOSYS
#define ENOSYS 89
#endif

#ifndef ELOOP
#define ELOOP 90
#endif

#ifndef ERESTART
#define ERESTART 91
#endif

#ifndef ESTRPIPE
#define ESTRPIPE 92
#endif

#ifndef ENOTEMPTY
#define ENOTEMPTY 93
#endif

#ifndef EUSERS
#define EUSERS 94
#endif

#ifndef ENOTSOCK
#define ENOTSOCK 95
#endif

#ifndef EDESTADDRREQ
#define EDESTADDRREQ 96
#endif

#ifndef EMSGSIZE
#define EMSGSIZE 97
#endif

#ifndef EPROTOTYPE
#define EPROTOTYPE 98
#endif

#ifndef ENOPROTOOPT
#define ENOPROTOOPT 99
#endif

#ifndef EPROTONOSUPPORT
#define EPROTONOSUPPORT 120
#endif

#ifndef ESOCKTNOSUPPORT
#define ESOCKTNOSUPPORT 121
#endif

#ifndef EOPNOTSUPP
#define EOPNOTSUPP 122
#endif

#ifndef ENOTSUP
#define ENOTSUP EOPNOTSUPP
#endif

#ifndef EPFNOSUPPORT
#define EPFNOSUPPORT 123
#endif

#ifndef EAFNOSUPPORT
#define EAFNOSUPPORT 124
#endif

#ifndef EADDRINUSE
#define EADDRINUSE 125
#endif

#ifndef EADDRNOTAVAIL
#define EADDRNOTAVAIL 126
#endif

#ifndef ENETDOWN
#define ENETDOWN 127
#endif

#ifndef ENETUNREACH
#define ENETUNREACH 128
#endif

#ifndef ENETRESET
#define ENETRESET 129
#endif

#ifndef ECONNABORTED
#define ECONNABORTED 130
#endif

#ifndef ECONNRESET
#define ECONNRESET 131
#endif

#ifndef ENOBUFS
#define ENOBUFS 132
#endif

#ifndef EISCONN
#define EISCONN 133
#endif

#ifndef ENOTCONN
#define ENOTCONN 134
#endif

#ifndef EUCLEAN
#define EUCLEAN 135
#endif

#ifndef ENOTNAM
#define ENOTNAM 137
#endif

#ifndef ENAVAIL
#define ENAVAIL 138
#endif

#ifndef EISNAM
#define EISNAM 139
#endif

#ifndef EREMOTEIO
#define EREMOTEIO 140
#endif

#ifndef ESHUTDOWN
#define ESHUTDOWN 143
#endif

#ifndef ETOOMANYREFS
#define ETOOMANYREFS 144
#endif

#ifndef ETIMEDOUT
#define ETIMEDOUT 145
#endif

#ifndef ECONNREFUSED
#define ECONNREFUSED 146
#endif

#ifndef EHOSTDOWN
#define EHOSTDOWN 147
#endif

#ifndef EHOSTUNREACH
#define EHOSTUNREACH 148
#endif

#ifndef EWOULDBLOCK
#define EWOULDBLOCK EAGAIN
#endif

#ifndef EALREADY
#define EALREADY 149
#endif

#ifndef EINPROGRESS
#define EINPROGRESS 150
#endif

#ifndef ESTALE
#define ESTALE 151
#endif

#ifndef ECANCELED
#define ECANCELED 158
#endif

#ifndef ENOMEDIUM
#define ENOMEDIUM 159
#endif

#ifndef EMEDIUMTYPE
#define EMEDIUMTYPE 160
#endif

#ifndef ENOKEY
#define ENOKEY 161
#endif

#ifndef EKEYEXPIRED
#define EKEYEXPIRED 162
#endif

#ifndef EKEYREVOKED
#define EKEYREVOKED 163
#endif

#ifndef EKEYREJECTED
#define EKEYREJECTED 164
#endif

#ifndef EOWNERDEAD
#define EOWNERDEAD 165
#endif

#ifndef ENOTRECOVERABLE
#define ENOTRECOVERABLE 166
#endif

#ifndef ERFKILL
#define ERFKILL 167
#endif

#ifndef EHWPOISON
#define EHWPOISON 168
#endif

#ifndef EDQUOT
#define EDQUOT 1133
#endif

#endif /* __ERRNO_TABLE_H__ */
