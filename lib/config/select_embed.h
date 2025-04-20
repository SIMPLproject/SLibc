/* this file is just to choose which .c file to embed for native or archive _build.c file */

#define __TMP2(x, y) x ## y
#define __TMP1(x, y) __TMP2(x, y)

#if defined(HAS_AVX) || defined(HAS_SSE)
  #define __EMBED_NAME(x) __TMP1(x, _simd.c)
#else
  #define __EMBED_NAME(x) __TMP1(x, _generic.c)
#endif

#define STR(x) #x
#define XSTR(x) STR(x)

#define simpl_embed_name(x) XSTR(__EMBED_NAME(x))
