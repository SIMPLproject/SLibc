#define _POSIX_C_SOURCE 200809L

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern size_t slibc_strlen(const char *str);

static double diff_ns(struct timespec start, struct timespec end)
{
    const double secs = (double)(end.tv_sec - start.tv_sec);
    const double nsecs = (double)(end.tv_nsec - start.tv_nsec);
    return secs * 1e9 + nsecs;
}

static double run_benchmark(const char *label,
                            size_t (*fn)(const char *),
                            const char *buffer,
                            size_t len,
                            size_t iterations)
{
    struct timespec start = {0}, end = {0};
    volatile size_t guard = 0;

    /* Warm up the instruction cache. */
    for (size_t i = 0; i < 128; ++i)
    {
        guard += fn(buffer);
    }

    if (clock_gettime(CLOCK_MONOTONIC, &start) != 0)
    {
        perror("clock_gettime");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < iterations; ++i)
    {
        guard += fn(buffer);
    }

    if (clock_gettime(CLOCK_MONOTONIC, &end) != 0)
    {
        perror("clock_gettime");
        exit(EXIT_FAILURE);
    }

    const double total_ns = diff_ns(start, end);
    const double per_call = total_ns / (double)iterations;

    printf("%-14s len=%6zu bytes  ->  %9.2f ns/call\n", label, len, per_call);

    /* Prevent the compiler from optimizing the calls away. */
    guard += guard == 0;
    (void)guard;

    return per_call;
}

int main(void)
{
    const size_t lengths[] = {16, 64, 256, 1024, 4096, 16384, 65536};
    const size_t length_count = sizeof(lengths) / sizeof(lengths[0]);
    const size_t total_bytes_target = 512ull * 1024ull * 1024ull; /* 512 MiB per test */
    const size_t max_len = lengths[length_count - 1];

    char *buffer = NULL;
    if (posix_memalign((void **)&buffer, 32, max_len + 64) != 0)
    {
        fputs("Failed to allocate aligned buffer\n", stderr);
        return EXIT_FAILURE;
    }

    memset(buffer, 'A', max_len + 64);

    size_t (*glibc_strlen_ptr)(const char *) = strlen;

    puts("strlen benchmark comparing SLibc vs glibc");
    puts("(ns/call, lower is better)\n");

    for (size_t i = 0; i < length_count; ++i)
    {
        const size_t len = lengths[i];
        size_t iterations = total_bytes_target / len;
        if (iterations < 1)
        {
            iterations = 1;
        }

        buffer[len - 1] = 'A';
        buffer[len] = '\0';

        const double slibc_time = run_benchmark("SLibc strlen", slibc_strlen, buffer, len, iterations);
        const double glibc_time = run_benchmark("glibc strlen", glibc_strlen_ptr, buffer, len, iterations);

        const double ratio = glibc_time / slibc_time;
        printf("len=%6zu bytes -> ratio glibc/SLibc = %.2fx\n\n", len, ratio);
    }

    free(buffer);
    return EXIT_SUCCESS;
}
