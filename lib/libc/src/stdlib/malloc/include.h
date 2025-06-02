/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:24:26 by bonsthie          #+#    #+#             */
/*   Updated: 2025/06/02 20:34:41 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
#define INCLUDE_H

#include <config.h>
#include <stdio.h>
#include <string.h>
#include <sys/cdefs.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <unistd.h>

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

#ifndef __GNUC__
#    define __builtin_align_up(x, align) (((x) + (align - 1)) & ~(align - 1))
#endif

#define ALIGNMENT 16
#define ALIGN(size, alignment) (((size) + (alignment - 1)) & ~(alignment - 1))
#define MMAP_THRESHOLD (128 * 1024)
#define MMAP_SIZE (128 * 1024)
#define MMAP_ALIGN(size) (((size) + (MMAP_SIZE - 1)) & ~(MMAP_SIZE - 1))
#define BIN_COUNT 10
#define BIN_MAX_SIZE 128
#define CACHE_SIZE_L1 32768
#define CACHE_SIZE_L2 262144
#define UNIT 16
#define BITMAP_SIZE 1024
#define BLOCK_UNIT_SIZE 32
#define MEMORY_POOL_SIZE (BITMAP_SIZE * BLOCK_UNIT_SIZE)
#define BLOCK_SIZE ALIGN(sizeof(Block), ALIGNMENT)
#define MAX_BLOCK_SIZE 1024 * 1024
#define PAGESIZE 4096 // to change

typedef enum { NO_CACHE = 0, L1_CACHE = 1, L2_CACHE = 2, L3_CACHE = 3 } CacheLevel;

#define CACHE_LEVEL

typedef enum { TINY = 0, SMALL = 1, LARGE = 2 } BinType;

/*
 * get cache level
 * 0: no cache
 * 1: L1 cache
 * 2: L2 cache
 * 3: L3 cache
 *  this is used to determine the cache size
 */

void  get_cache_info();
void *allocate_cache(size_t size);

/*
 * this structure is used to store the block information
 * size: size of the block
 * next: pointer to the next block
 * free: flag to indicate if the block is free
 * aligned_address: aligned address of the block
 * is_mmap: flag to indicate if the block is allocated using mmap
 */

struct group {
    struct meta  *meta;
    unsigned char active_idx : 5;
    char          pad[UNIT - sizeof(struct meta *) - 1];
    unsigned char storage[];
};

typedef struct Block {
    size_t        size;
    struct Block *next;
    int           free;
    void         *aligned_address;
    int           is_mmap;
} Block;

typedef struct MemoryAllocator {
    Block *freelist;
    int    allocated_blocks;
    size_t block_size;
    Block *bins[BIN_COUNT];
} MemoryAllocator;

/* function that will be avx optimisze */
#define request_space_mmap ARCH_SYM(request_space_mmap)
#define find_free_block ARCH_SYM(find_free_block)
#define split_block ARCH_SYM(split_block)
#define request_space ARCH_SYM(request_space)

/* block utils */

void __hidden  coalesce_free_blocks();
void __hidden *find_free_block(size_t size, size_t alignment);
void __hidden  split_block(Block *block, size_t size, size_t alignment);
void __hidden  initialize_allocator();
/* memory allocation */

void __hidden  *request_space_mmap(size_t size, size_t alignment);
Block __hidden *request_space(Block *last, size_t size, size_t alignment);
void __hidden   check_alignment(void *aligned_address);
void __hidden  *_aligned_alloc(size_t alignment, size_t size);
void __hidden   _aligned_free(void *ptr);

#define __vector __attribute__((vector_size(16)))

#endif
