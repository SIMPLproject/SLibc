#ifndef __AUXV_H__
#define __AUXV_H__

#include <sys/cdefs.h>
#include <link.h>

static inline Elf_auxv_t *get_auxv_from_env(char **env) {
	while (*env)
		env++;
	return (Elf_auxv_t *)++env;
}

static inline Elf_auxv_t *get_auxv_from_argv(char **argv) {
	while (*argv)
		argv++;
	return get_auxv_from_env(++argv);
}

const ElfW(Ehdr) *get_main_prgm_hdr_from_auxv(void *arg) __hidden;

#endif /* __AUXV_H__ */
