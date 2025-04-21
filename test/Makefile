all : compile
	@./test_string

compile :
	@clang -nostdlib -static -g -O0 -fno-stack-protector -fno-pie -ffreestanding  \
		../bin/lib/crt1.o ../bin/lib/crti.o ../bin/lib/crtn.o \
		string.c ../bin/lib/libc.a \
		-I ../bin/include \
		-D NO_TEST_EXIT \
		-o test_string

.PHONY: compile all
