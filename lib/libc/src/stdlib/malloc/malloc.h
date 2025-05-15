#ifndef MALLOC_H
#define MALLOC_H

#include <unistd.h>
#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#if !defined(__HAS_ASSERT__)
#define assert(...) 
#define __assert_fail(...)
#endif


/*
	* ALIGNMENT: alignment of the block 
	* ALIGN(size, alignment): align the size to the alignment
	* MMAP_THRESHOLD: threshold to use mmap
	* MMAP_SIZE: size of the mmap block
	* MMAP_ALIGN(size): align the size to the mmap size
	* BIN_COUNT: number of bins
	* BIN_MAX_SIZE: maximum size of the bin
	* CACHE_SIZE_L1: size of the L1 cache
	* CACHE_SIZE_L2: size of the L2 cache
*/

#define ALIGNMENT 16
#define ALIGN(size, alignment) (((size) + (alignment - 1)) & ~(alignment - 1))
#define MMAP_THRESHOLD (128 * 1024) 
#define MMAP_SIZE (128 * 1024)
#define MMAP_ALIGN(size) (((size) + (MMAP_SIZE - 1)) & ~(MMAP_SIZE - 1))
#define BIN_COUNT 10
#define BIN_MAX_SIZE 128
#define CACHE_SIZE_L1 32768
#define CACHE_SIZE_L2 262144

/* 
	* get cache level 
	* 0: no cache
	* 1: L1 cache
	* 2: L2 cache
	* 3: L3 cache
	*  this is used to determine the cache size
*/

__hidden void get_cache_info();
__hidden void *allocate_cache(size_t size);

/*
	* this structure is used to store the block information 
	* size: size of the block
	* next: pointer to the next block
	* free: flag to indicate if the block is free
	* aligned_address: aligned address of the block
	* is_mmap: flag to indicate if the block is allocated using mmap
*/

typedef struct Block {
    size_t size;
    struct Block *next;
    int free;
	void *aligned_address;
	int is_mmap;
} Block;

#define MBLOCK_SIZE ALIGN(sizeof(Block), ALIGNMENT)


/* block utils */

__hidden void coalesce_free_blocks(); 
__hidden Block *find_free_block(Block **last, size_t size, size_t alignment); 
__hidden void split_block(Block *block, size_t size, size_t alignment);

/* memory allocation */

__hidden void *request_space_mmap(size_t size, size_t alignment);
__hidden Block *request_space_sbrk(Block *last, size_t size, size_t alignment);
__hidden void check_alignment(void *aligned_address);
__hidden void *_aligned_alloc(size_t alignment, size_t size);

/* memory leak detection and utils */

void check_for_leaks();
/* void hexdump(void *ptr, size_t size); */


__hidden void* _mmap(void* start, size_t len, int prot, int flags, int fd, size_t offset); 
__hidden int _munmap(void* addr, size_t length); 

__hidden void * _sbrk(intptr_t increment);
#endif // MALLOC_H
