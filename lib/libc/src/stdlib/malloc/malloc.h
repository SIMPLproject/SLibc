#ifndef MALLOC_H
#define MALLOC_H

#include <sys/mman.h>
#include <config.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BIN_SIZE 512
#define PAGESIZE 4096 // to change  for a dynamic one or a compile time optimisation
#define NUM_SMALL_ALLOCS 1000
#define NUM_BINS 64
#define NUM_LARGE_ALLOCS 100
#define MAX_ALLOCATION_SIZE (1 << 20)
#define BLOCK_UNIT_SIZE 1024
#define MEMORY_POOL_SIZE (1024 * 1024 * 1024)
#define BITMAP_SIZE (MEMORY_POOL_SIZE / BLOCK_UNIT_SIZE)
#define ALIGNMENT 32
#define BLOCK_SIZE 4096
#define MMAP_THRESHOLD (512 * 1024)
#define CANARY_START_VALUE 0xDEADBEEF
#define CANARY_END_VALUE 0xCAFEBABE

typedef struct __attribute__((aligned(ALIGNMENT))) Block {
    size_t        size;
    uint32_t      start_canary;
    int           free;
    int           is_mmap;
    struct Block *next;
    void         *aligned_address;
    uint32_t      end_canary;
} Block;

#define IS_ALIGNED(ptr)                                                                            \
    (((uintptr_t *)ptr)[-1] > (uintptr_t)ptr - PAGESIZE && ((uintptr_t *)ptr)[-1] < (uintptr_t)ptr)

int              posix_memalign(void **memptr, size_t alignment, size_t size);

int get_bin_index(size_t size);
void *find_free_block(size_t size, size_t alignment);

#endif // MALLOC_H
