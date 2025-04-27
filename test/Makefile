all : compile
	@./test_string

compile :
	@clang -nostdlib -static -g -O0 -fno-stack-protector -fno-pie -ffreestanding  \
		../bin/lib/crt1.o ../bin/lib/crti.o ../bin/lib/crtn.o \
		string.c ../bin/lib/libc.a \
		-I ../bin/include \
		-D NO_TEST_EXIT \
		-o test_string


LIBDIR     := $(realpath ../bin/lib)
INCDIR     := $(realpath ../bin/include)
DYN_LINKER := ../bin/lib/ld.so

ld:
	clang -nostdlib -nostartfiles -g\
		-fuse-ld=lld \
		-o test \
		-Wl,--enable-new-dtags \
		-Wl,--rpath=$(LIBDIR) \
		-Wl,--dynamic-linker=$(DYN_LINKER) \
		$(LIBDIR)/crt1.o test.c \
		-L$(LIBDIR) -lc \
		-I$(INCDIR)

.PHONY: compile all
