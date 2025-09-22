CC ?= clang
CFLAGS ?= -O3 -march=native -g
CFLAGS += -std=gnu11 -Wall -Wextra -fno-builtin

SLIBC_INCLUDES = -I../include -I../lib/config -I../lib/libc/include

BENCH_CFLAGS = $(CFLAGS) -D_GNU_SOURCE
SLIBC_CFLAGS = $(CFLAGS) -msse4 -fno-builtin-strlen $(SLIBC_INCLUDES)

SLIBC_SRC = ../lib/libc/src/string/strlen/strlen_simd.c
WRAPPER_SRC = slibc_strlen_wrapper.c
BENCH_SRC = strlen_bench.c

OBJS = strlen_bench.o slibc_strlen_wrapper.o strlen_simd.o

all: strlen_bench

strlen_simd.o: $(SLIBC_SRC)
	$(CC) $(SLIBC_CFLAGS) -c $< -o $@

slibc_strlen_wrapper.o: $(WRAPPER_SRC)
	$(CC) $(SLIBC_CFLAGS) -c $< -o $@

strlen_bench.o: $(BENCH_SRC)
	$(CC) $(BENCH_CFLAGS) -c $< -o $@

strlen_bench: $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

run: strlen_bench
	./strlen_bench

clean:
	rm -f *.o strlen_bench

.PHONY: all run clean
