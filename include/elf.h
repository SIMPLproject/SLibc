#ifndef __ELF_H__
#define __ELF_H__

/*
 * elf.h - ELF file format definitions for 32-bit and 64-bit architectures
 *
 * Provides:
 *  - Common ELF basic data types (Byte, Half, Word, Xword, etc.)
 *  - 64-bit and 32-bit ELF header structures
 *  - Program header, section header, symbol and relocation entry structures
 *  - Enumeration constants for file types, machine types, segment types,
 *    section types, and flags
 */

#include <stdint.h>

//////////////////////////////////////////////////////////////
///				ELF COMMON DATA TYPES
//////////////////////////////////////////////////////////////

// 64-bit basic types
typedef uint8_t  Elf64_Byte;   //  8-bit unsigned integer
typedef uint16_t Elf64_Half;   // 16-bit unsigned integer
typedef uint32_t Elf64_Word;   // 32-bit unsigned integer
typedef int32_t  Elf64_Sword;  // 32-bit signed integer
typedef uint64_t Elf64_Xword;  // 64-bit unsigned integer
typedef int64_t  Elf64_Sxword; // 64-bit signed integer
typedef uint64_t Elf64_Addr;   // 64-bit virtual address
typedef uint64_t Elf64_Off;    // 64-bit file offset

// 32-bit basic types
typedef uint8_t  Elf32_Byte;  //  8-bit unsigned integer
typedef uint16_t Elf32_Half;  // 16-bit unsigned integer
typedef uint32_t Elf32_Word;  // 32-bit unsigned integer
typedef int32_t  Elf32_Sword; // 32-bit signed integer
typedef uint32_t Elf32_Addr;  // 32-bit virtual address
typedef uint32_t Elf32_Off;   // 32-bit file offset

//////////////////////////////////////////////////////////////
///				64-BIT ELF HEADER
//////////////////////////////////////////////////////////////

typedef struct {
    Elf64_Byte e_ident[16]; // ELF identification bytes
    Elf64_Half e_type;      // Object file type
    Elf64_Half e_machine;   // Architecture
    Elf64_Word e_version;   // Object file version
    Elf64_Addr e_entry;     // Entry point virtual address
    Elf64_Off  e_phoff;     // Program header table file offset
    Elf64_Off  e_shoff;     // Section header table file offset
    Elf64_Word e_flags;     // Processor-specific flags
    Elf64_Half e_ehsize;    // ELF header size in bytes
    Elf64_Half e_phentsize; // Program header entry size
    Elf64_Half e_phnum;     // Number of program header entries
    Elf64_Half e_shentsize; // Section header entry size
    Elf64_Half e_shnum;     // Number of section header entries
    Elf64_Half e_shstrndx;  // Section header string table index
} Elf64_Ehdr;

typedef struct {
    Elf64_Byte ei_magic[4];   // Magic number: 0x7F 'E' 'L' 'F'
    Elf64_Byte ei_class;      // File class (32 or 64 bit)
    Elf64_Byte ei_data;       // Data encoding (LE/BE)
    Elf64_Byte ei_version;    // ELF version (always 1)
    Elf64_Byte ei_osabi;      // OS ABI identification
    Elf64_Byte ei_abiversion; // ABI version
    Elf64_Byte ei_pad[7];     // Padding (should be zero)
} Elf64_EIdent;

//////////////////////////////////////////////////////////////
///				64-BIT PROGRAM HEADER
//////////////////////////////////////////////////////////////

typedef struct {
    Elf64_Word  p_type;   // Segment type
    Elf64_Word  p_flags;  // Segment flags
    Elf64_Off   p_offset; // Offset in file
    Elf64_Addr  p_vaddr;  // Virtual address in memory
    Elf64_Addr  p_paddr;  // Physical address (unused)
    Elf64_Xword p_filesz; // Size in file
    Elf64_Xword p_memsz;  // Size in memory
    Elf64_Xword p_align;  // Alignment
} Elf64_Phdr;

//////////////////////////////////////////////////////////////
///				64-BIT SECTION HEADER
//////////////////////////////////////////////////////////////

typedef struct {
    Elf64_Word  sh_name;      // Section name (string table index)
    Elf64_Word  sh_type;      // Section type
    Elf64_Xword sh_flags;     // Section flags
    Elf64_Addr  sh_addr;      // Virtual address in memory
    Elf64_Off   sh_offset;    // Offset in file
    Elf64_Xword sh_size;      // Size in bytes
    Elf64_Word  sh_link;      // Link to another section
    Elf64_Word  sh_info;      // Additional section information
    Elf64_Xword sh_addralign; // Alignment
    Elf64_Xword sh_entsize;   // Entry size if section holds table
} Elf64_Shdr;

//////////////////////////////////////////////////////////////
///				64-BIT SYMBOL TABLE ENTRY
//////////////////////////////////////////////////////////////

typedef struct {
    Elf64_Word  st_name;  // Symbol name (string table index)
    Elf64_Byte  st_info;  // Type and binding attributes
    Elf64_Byte  st_other; // Visibility
    Elf64_Half  st_shndx; // Section index
    Elf64_Addr  st_value; // Symbol value (address)
    Elf64_Xword st_size;  // Size of the symbol
} Elf64_Sym;

//////////////////////////////////////////////////////////////
///				64-BIT RELOCATION ENTRIES
//////////////////////////////////////////////////////////////

typedef struct {
    Elf64_Addr  r_offset; // Offset where to apply relocation
    Elf64_Xword r_info;   // Symbol index and type of relocation
} Elf64_Rel;

typedef struct {
    Elf64_Addr   r_offset; // Offset where to apply relocation
    Elf64_Xword  r_info;   // Symbol index and type
    Elf64_Sxword r_addend; // Addend used to compute value
} Elf64_Rela;

//////////////////////////////////////////////////////////////
///				64-BIT ENUMERATIONS
//////////////////////////////////////////////////////////////

typedef enum {
    ET_NONE = 0,        // No file type
    ET_REL = 1,         // Relocatable file
    ET_EXEC = 2,        // Executable file
    ET_DYN = 3,         // Shared object file
    ET_CORE = 4,        // Core file
    ET_LOOS = 0xFE00,   // OS-specific
    ET_HIOS = 0xFEFF,   // OS-specific
    ET_LOPROC = 0xFF00, // Processor-specific
    ET_HIPROC = 0xFFFF  // Processor-specific
} Elf64_EType;

typedef enum {
    EM_NONE = 0,        // No machine
    EM_M32 = 1,         // AT&T WE 32100
    EM_SPARC = 2,       // SPARC
    EM_386 = 3,         // Intel 80386
    EM_68K = 4,         // Motorola 68000
    EM_88K = 5,         // Motorola 88000
    EM_IAMCU = 6,       // Intel MCU
    EM_860 = 7,         // Intel 80860
    EM_MIPS = 8,        // MIPS R3000
    EM_ARM = 40,        // ARM
    EM_X86_64 = 62,     // x86-64
    EM_AARCH64 = 183,   // ARM 64-bit
    EM_RISCV = 243,     // RISC-V
    EM_LOPROC = 0xFF00, // Processor-specific
    EM_HIPROC = 0xFFFF  // Processor-specific
} Elf64_EMachine;

typedef enum {
    PT_NULL = 0,            // Unused segment
    PT_LOAD = 1,            // Loadable segment
    PT_DYNAMIC = 2,         // Dynamic linking info
    PT_INTERP = 3,          // Interpreter path
    PT_NOTE = 4,            // Auxiliary info
    PT_SHLIB = 5,           // Reserved
    PT_PHDR = 6,            // Program header
    PT_TLS = 7,             // Thread-local storage
    PT_LOOS = 0x60000000,   // OS-specific
    PT_HIOS = 0x6FFFFFFF,   // OS-specific
    PT_LOPROC = 0x70000000, // Processor-specific
    PT_HIPROC = 0x7FFFFFFF  // Processor-specific
} Elf64_PType;

typedef enum {
    PF_X = 0x1, // Execute
    PF_W = 0x2, // Write
    PF_R = 0x4  // Read
} Elf64_PFlags;

typedef enum {
    SHT_NULL = 0,     // Inactive
    SHT_PROGBITS = 1, // Program data
    SHT_SYMTAB = 2,   // Symbol table
    SHT_STRTAB = 3,   // String table
    SHT_RELA = 4,     // Relocations w/ addends
    SHT_HASH = 5,     // Hash table
    SHT_DYNAMIC = 6,  // Dynamic linking info
    SHT_NOTE = 7,     // Notes
    SHT_NOBITS = 8,   // Uninitialized data
    SHT_REL = 9,      // Relocations w/o addends
    SHT_DYNSYM = 11   // Dynamic symbol table
} Elf64_ShType;

typedef enum {
    SHF_WRITE = 0x1,    // Writable
    SHF_ALLOC = 0x2,    // Occupies memory
    SHF_EXECINSTR = 0x4 // Executable
} Elf64_ShFlags;

//////////////////////////////////////////////////////////////
///				32-BIT ELF HEADER
//////////////////////////////////////////////////////////////

typedef struct {
    Elf32_Byte e_ident[16]; // ELF identification bytes
    Elf32_Half e_type;      // Object file type
    Elf32_Half e_machine;   // Architecture
    Elf32_Word e_version;   // Object file version
    Elf32_Addr e_entry;     // Entry point virtual address
    Elf32_Off  e_phoff;     // Program header table file offset
    Elf32_Off  e_shoff;     // Section header table file offset
    Elf32_Word e_flags;     // Processor-specific flags
    Elf32_Half e_ehsize;    // ELF header size in bytes
    Elf32_Half e_phentsize; // Program header entry size
    Elf32_Half e_phnum;     // Number of program header entries
    Elf32_Half e_shentsize; // Section header entry size
    Elf32_Half e_shnum;     // Number of section header entries
    Elf32_Half e_shstrndx;  // Section header string table index
} Elf32_Ehdr;

typedef struct {
    Elf32_Byte ei_magic[4];   // Magic number: 0x7F 'E' 'L' 'F'
    Elf32_Byte ei_class;      // File class (32 bit)
    Elf32_Byte ei_data;       // Data encoding (LE/BE)
    Elf32_Byte ei_version;    // ELF version (always 1)
    Elf32_Byte ei_osabi;      // OS ABI identification
    Elf32_Byte ei_abiversion; // ABI version
    Elf32_Byte ei_pad[7];     // Padding (should be zero)
} Elf32_EIdent;

//////////////////////////////////////////////////////////////
///				32-BIT PROGRAM HEADER
//////////////////////////////////////////////////////////////

typedef struct {
    Elf32_Word p_type;   // Segment type
    Elf32_Off  p_offset; // Offset in file
    Elf32_Addr p_vaddr;  // Virtual address in memory
    Elf32_Addr p_paddr;  // Physical address (unused)
    Elf32_Word p_filesz; // Size in file
    Elf32_Word p_memsz;  // Size in memory
    Elf32_Word p_flags;  // Segment flags
    Elf32_Word p_align;  // Alignment
} Elf32_Phdr;

//////////////////////////////////////////////////////////////
///				32-BIT SECTION HEADER
//////////////////////////////////////////////////////////////

typedef struct {
    Elf32_Word sh_name;      // Section name (string table index)
    Elf32_Word sh_type;      // Section type
    Elf32_Word sh_flags;     // Section flags
    Elf32_Addr sh_addr;      // Virtual address in memory
    Elf32_Off  sh_offset;    // Offset in file
    Elf32_Word sh_size;      // Size in bytes
    Elf32_Word sh_link;      // Link to another section
    Elf32_Word sh_info;      // Additional section information
    Elf32_Word sh_addralign; // Alignment
    Elf32_Word sh_entsize;   // Entry size if section holds table
} Elf32_Shdr;

//////////////////////////////////////////////////////////////
///				32-BIT SYMBOL TABLE ENTRY
//////////////////////////////////////////////////////////////

typedef struct {
    Elf32_Word st_name;  // Symbol name (string table index)
    Elf32_Addr st_value; // Symbol value (address)
    Elf32_Word st_size;  // Size of the symbol
    Elf32_Byte st_info;  // Type and binding attributes
    Elf32_Byte st_other; // Visibility
    Elf32_Half st_shndx; // Section index
} Elf32_Sym;

//////////////////////////////////////////////////////////////
///				32-BIT RELOCATION ENTRIES
//////////////////////////////////////////////////////////////

typedef struct {
    Elf32_Addr r_offset; // Offset where to apply relocation
    Elf32_Word r_info;   // Symbol index and type of relocation
} Elf32_Rel;

typedef struct {
    Elf32_Addr  r_offset; // Offset where to apply relocation
    Elf32_Word  r_info;   // Symbol index and type
    Elf32_Sword r_addend; // Addend used to compute value
} Elf32_Rela;

//////////////////////////////////////////////////////////////
///				32-BIT ENUMERATIONS
//////////////////////////////////////////////////////////////

typedef enum {
    ET_NONE32 = 0,        // No file type
    ET_REL32 = 1,         // Relocatable file
    ET_EXEC32 = 2,        // Executable file
    ET_DYN32 = 3,         // Shared object file
    ET_CORE32 = 4,        // Core file
    ET_LOOS32 = 0xFE00,   // OS-specific
    ET_HIOS32 = 0xFEFF,   // OS-specific
    ET_LOPROC32 = 0xFF00, // Processor-specific
    ET_HIPROC32 = 0xFFFF  // Processor-specific
} Elf32_EType;

typedef enum {
    EM_NONE32 = 0,        // No machine
    EM_M3232 = 1,         // AT&T WE 32100
    EM_SPARC32 = 2,       // SPARC
    EM_38632 = 3,         // Intel 80386
    EM_68K32 = 4,         // Motorola 68000
    EM_88K32 = 5,         // Motorola 88000
    EM_IAMCU32 = 6,       // Intel MCU
    EM_86032 = 7,         // Intel 80860
    EM_MIPS32 = 8,        // MIPS R3000
    EM_ARM32 = 40,        // ARM
    EM_386_32 = 3,        // Duplicate alias for 80386
    EM_XTENSA32 = 18,     // Tensilica Xtensa
    EM_LOPROC32 = 0xFF00, // Processor-specific
    EM_HIPROC32 = 0xFFFF  // Processor-specific
} Elf32_EMachine;

typedef enum {
    PT_NULL32 = 0,            // Unused segment
    PT_LOAD32 = 1,            // Loadable segment
    PT_DYNAMIC32 = 2,         // Dynamic linking info
    PT_INTERP32 = 3,          // Interpreter path
    PT_NOTE32 = 4,            // Auxiliary info
    PT_SHLIB32 = 5,           // Reserved
    PT_PHDR32 = 6,            // Program header
    PT_TLS32 = 7,             // Thread-local storage
    PT_LOOS32 = 0x60000000,   // OS-specific
    PT_HIOS32 = 0x6FFFFFFF,   // OS-specific
    PT_LOPROC32 = 0x70000000, // Processor-specific
    PT_HIPROC32 = 0x7FFFFFFF  // Processor-specific
} Elf32_PType;

typedef enum {
    PF_X32 = 0x1, // Execute
    PF_W32 = 0x2, // Write
    PF_R32 = 0x4  // Read
} Elf32_PFlags;

typedef enum {
    SHT_NULL32 = 0,     // Inactive
    SHT_PROGBITS32 = 1, // Program data
    SHT_SYMTAB32 = 2,   // Symbol table
    SHT_STRTAB32 = 3,   // String table
    SHT_RELA32 = 4,     // Relocations w/ addends
    SHT_HASH32 = 5,     // Hash table
    SHT_DYNAMIC32 = 6,  // Dynamic linking info
    SHT_NOTE32 = 7,     // Notes
    SHT_NOBITS32 = 8,   // Uninitialized data
    SHT_REL32 = 9,      // Relocations w/o addends
    SHT_DYNSYM32 = 11   // Dynamic symbol table
} Elf32_ShType;

typedef enum {
    SHF_WRITE32 = 0x1,    // Writable
    SHF_ALLOC32 = 0x2,    // Occupies memory
    SHF_EXECINSTR32 = 0x4 // Executable
} Elf32_ShFlags;

typedef struct {
    uint32_t a_type;
    union {
        uint32_t a_val;
    } a_un;
} Elf32_auxv_t;
typedef struct {
    uint64_t a_type;
    union {
        uint64_t a_val;
    } a_un;
} Elf64_auxv_t;


/* ELF auxiliary vector types (Elf32_auxv_t.a_type / Elf64_auxv_t.a_type) */

#define AT_NULL              0   /* End of vector */
#define AT_IGNORE            1   /* Entry should be ignored */
#define AT_EXECFD            2   /* File descriptor of program to load */
#define AT_PHDR              3   /* Pointer to program headers */
#define AT_PHENT             4   /* Size of one program header entry */
#define AT_PHNUM             5   /* Number of program header entries */
#define AT_PAGESZ            6   /* System page size */
#define AT_BASE              7   /* Base address of interpreter */
#define AT_FLAGS             8   /* Flags (unused) */
#define AT_ENTRY             9   /* Entry point of program */
#define AT_NOTELF           10   /* Program is not an ELF file */
#define AT_UID              11   /* Real user ID */
#define AT_EUID             12   /* Effective user ID */
#define AT_GID              13   /* Real group ID */
#define AT_EGID             14   /* Effective group ID */

#define AT_PLATFORM         15   /* String identifying CPU/OS platform */
#define AT_HWCAP            16   /* CPU capabilities bitmask */
#define AT_CLKTCK           17   /* Frequency of times() ticks per second */

#define AT_FPUCW            18   /* Initial FPU control word */

#define AT_DCACHEBSIZE      19   /* Data cache block size */
#define AT_ICACHEBSIZE      20   /* Instruction cache block size */
#define AT_UCACHEBSIZE      21   /* Unified cache block size */

#define AT_IGNOREPPC        22   /* Entry ignored on PowerPC */

#define AT_SECURE           23   /* Boolean: program is running in secure mode */

#define AT_BASE_PLATFORM    24   /* Real platform name string */

#define AT_RANDOM           25   /* Address of 16 random bytes */

#define AT_HWCAP2           26   /* Additional CPU capabilities */

#define AT_EXECFN           31   /* Filename of executed program */

#define AT_SYSINFO          32   /* Pointer to vDSO/system-call page */
#define AT_SYSINFO_EHDR     33   /* Address of vDSO ELF header */

#define AT_L1I_CACHESHAPE   34   /* Encoded shape of L1 instruction cache */
#define AT_L1D_CACHESHAPE   35   /* Encoded shape of L1 data cache */
#define AT_L2_CACHESHAPE    36   /* Encoded shape of L2 cache */
#define AT_L3_CACHESHAPE    37   /* Encoded shape of L3 cache */

#define AT_L1I_CACHESIZE    40   /* Size of L1 instruction cache (bytes) */
#define AT_L1I_CACHEGEOMETRY 41  /* Encoded geometry of L1 I-cache */
#define AT_L1D_CACHESIZE    42   /* Size of L1 data cache (bytes) */
#define AT_L1D_CACHEGEOMETRY 43  /* Encoded geometry of L1 D-cache */
#define AT_L2_CACHESIZE     44   /* Size of L2 cache (bytes) */
#define AT_L2_CACHEGEOMETRY 45   /* Encoded geometry of L2 cache */
#define AT_L3_CACHESIZE     46   /* Size of L3 cache (bytes) */
#define AT_L3_CACHEGEOMETRY 47   /* Encoded geometry of L3 cache */

#define AT_MINSIGSTKSZ      51   /* Minimum stack size for signal handlers */


#endif /* __ELF_H__ */
