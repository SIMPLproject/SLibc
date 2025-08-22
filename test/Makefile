all : ld

compile_static :
	@clang -nostdlib -static -g -O0 -fno-stack-protector -fno-pie -ffreestanding  \
		../bin/lib/crt1.o ../bin/lib/crti.o ../bin/lib/crtn.o \
		string.c ../bin/lib/libc.a \
		-I ../bin/include \
		-D NO_TEST_EXIT \
		-o test_string_static

compile_dynamic:
	clang -nostdlib -nostartfiles \
		$(SLIBC_PATH)/lib/crt1.o \
		$(SLIBC_PATH)/lib/crti.o \
		$(SLIBC_PATH)/lib/crtn.o \
		string.c \
		-L$(SLIBC_PATH)/lib \
		-Wl,--dynamic-linker=/lib64/ld-linux-x86-64.so.2 \
		-Wl,-rpath,$(SLIBC_PATH)/lib \
		-Wl,-rpath-link,$(SLIBC_PATH)/lib \
		-D NO_TEST_EXIT \
		-lc -o test_string_dynamic -g


LIBDIR     := $(realpath ../bin/lib)
INCDIR     := $(realpath ../bin/include)
DYN_LINKER := $(realpath ../bin/lib/ld.so)
# DYN_LINKER := /nfs/homes/babonnet/sgoinfre/glibc_out/lib/ld-linux-x86-64.so.2

ld:
	make -C ..
	clang -nostdlib -nostartfiles -g\
		-fuse-ld=lld \
		-o test \
		-Wl,--enable-new-dtags \
		-Wl,--rpath=$(LIBDIR) \
		-Wl,--dynamic-linker=$(DYN_LINKER) \
		$(LIBDIR)/crt1.o test.c \
		-L$(LIBDIR) -lc \
		-I$(INCDIR)

.PHONY: compile all ld

# mywrite.so -> depending on [libc.so (syscall)]
# myputstr.so -> depending on [mywrite.so (mywrite), libc.so (strlen)]
# program -> depending on [libc.so (start libc_start..), myputstr.so (myputstr)]
