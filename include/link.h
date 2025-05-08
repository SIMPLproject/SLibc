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

// struct to communicate with gdb ("gnu debugger" not "gueule de bois")
struct r_debug
  {
    int r_version;		/* Version number for this protocol.  */

    struct link_map *r_map;	/* Head of the chain of loaded objects.  */

    /* This is the address of a function internal to the run-time linker,
       that will always be called when the linker begins to map in a
       library or unmap it, and again when the mapping change is complete.
       The debugger can set a breakpoint at this address if it wants to
       notice shared object mapping changes.  */
    ElfW(Addr) r_brk;
    enum
      {
	/* This state value describes the mapping change taking place when
	   the `r_brk' address is called.  */
	RT_CONSISTENT,		/* Mapping change is complete.  */
	RT_ADD,			/* Beginning to add a new object.  */
	RT_DELETE,		/* Beginning to remove an object mapping.  */
      } r_state;

    ElfW(Addr) r_ldbase;	/* Base address the linker is loaded at.  */
  };

#endif /* __LINK_H__ */
