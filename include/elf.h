#ifndef __ELF_H__
#define __ELF_H__

enum at_flag {
    AT_NULL = 0,
    AT_IGNORE = 1,
    AT_EXECFD = 2,
    AT_PHDR = 3,
    AT_PHENT = 4,
    AT_PHNUM = 5,
    AT_PAGESZ = 6,
    AT_BASE = 7,
    AT_FLAGS = 8,
    AT_ENTRY = 9,
    AT_NOTELF = 10,
    AT_UID = 11,
    AT_EUID = 12,
    AT_GID = 13,
    AT_EGID = 14,
    AT_PLATFORM = 15,
    AT_HWCAP = 16,
	AT_CLKTCK = 17,
    AT_FPUCW = 18,
    AT_DCACHEBSIZE = 19,
    AT_ICACHEBSIZE = 20,
    AT_UCACHEBSIZE = 21,
    AT_IGNOREPPC = 22,
    AT_SECURE = 23,
    AT_BASE_PLATFORM = 24,
    AT_RANDOM = 25,
    AT_HWCAP2 = 26,
    AT_EXECFN = 31,
    AT_SYSINFO = 32,
    AT_SYSINFO_EHDR = 33,
    AT_L1I_CACHESHAPE = 34,
    AT_L1D_CACHESHAPE = 35,
    AT_L2_CACHESHAPE = 36,
    AT_L3_CACHESHAPE = 37,
    AT_L1I_CACHESIZE = 40,
    AT_L1I_CACHEGEOMETRY = 41,
    AT_L1D_CACHESIZE = 42,
    AT_L1D_CACHEGEOMETRY = 43,
    AT_L2_CACHESIZE = 44,
    AT_L2_CACHEGEOMETRY = 45,
    AT_L3_CACHESIZE = 46,
    AT_L3_CACHEGEOMETRY = 47,
    AT_MINSIGSTKSZ = 51
};


#endif // __ELF_H__
