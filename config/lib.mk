#list of all lib and there abi
LIBS=

LIBS+=libc
libc_NAME=libc
libc_ABI_NAME=libc.so.1
libc_VERSIONING_FILE=versioning/libc.v

LIBS+= ld
ld_NAME=ld
ld_ABI_NAME=ld-$(SYSTEM)-$(ARCH).so.1
