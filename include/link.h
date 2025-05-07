#ifndef __LINK_H__
#define __LINK_H__

#include <sys/arch.h>
#include <elf.h>

#define __ELF_TYPE __WORDSIZE

#define __ElfW_STRUCT(type, x) Elf##type##_##x
#define __ElfW_EXPEND(type, x) __ElfW_STRUCT(type, x)
#define ElfW(x) __ElfW_EXPEND(__ELF_TYPE, x)

typedef uint32_t Elf_Symndx;

typedef ElfW(auxv_t) Elf_auxv_t;

#endif /* __LINK_H__ */
