#include <config.h>
#include <sys/symbols.h>


#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(__find_free_block, void *, IFUNC_AVX | IFUNC_SSE, size_t size, size_t alignment);

#else

#include <select_embed.h>
#include simpl_embed_name(chunks)

#endif

libc_hidden_alias(find_free_block, __find_free_block)
simpl_weak_alias(find_free_block, __find_free_block)
