/**
 *	elf_identifier.h | ELF Enums
 *
 *	ELF Header fields:
 *		-	ELF_IdentIndices,
 *		-	ELF_Class,
 *		-	ELF_Endianness,
 *		-	ELF_OsAbi,
 *		-	ELF_ExType,
 *		-	ELF_Machine,
 *		-	ELF_Version,
 *
 *	ELF Program Header fields:
 *		-	ELF_ProgType,
 *		-	ELF_ProgFlags,
 *
 *	ELF Section Header fields:
 *		-	ELF_SectionType,
 *		-	ELF_SectionFlags,
 *
 *	ELF Symbol fields:
 *		-	ELF_SymbolVisibility,
 *		-	ELF_SymbolBind,
 *		-	ELF_SymbolType,
 *
 *	ELF Dynamic Symbol field:
 *		-	ELF_DynamicTag,
 *	
 *	These aren't used in the struct definitions to keep the original
 *	integer types for all fields.
 *
 *	Defining ELF_ENUMS_STRINGIFY above the <celf.h> include will
 *	generate sys/stringify functions for all enums, thus any call like :
 *
 *		ENUM_u_stringify(value);
 *
 *	with ENUM being one of the defined enums in this file, will return a
 *	pointer to a NULL-terminated string containing, if found, the string
 *	representation of 'value', else "UNKNOWN".
 *
 ** ***************************************************************************/

#ifndef __ELF_IDENTIFIER_H__
# define __ELF_IDENTIFIER_H__

# ifndef __ELF_ENUMS_STRINGIFY

enum	ELF_IdentIndices
{
	EI_MAG0			= 0,
	EI_MAG1			= 1,
	EI_MAG2			= 2,
	EI_MAG3			= 3,
	EI_CLASS		= 4,
	EI_DATA			= 5,
	EI_VERSION		= 6,
	EI_OSABI		= 7,
	EI_ABIVERSION	= 8,
};

enum	ELF_Class
{
	ELF_32BIT		= 1,
	ELF_64BIT		= 2,
};

enum	ELF_Endianness
{
	ELF_DATANONE	= 0x00,
	ELF_DATA2LSB	= 0x01,
	ELF_DATA2MSB	= 0x02,
};

enum	ELF_OsAbi
{
	EABI_SYSV		= 0x00,
	EABI_HPUX		= 0x01,
	EABI_NETBSD		= 0x02,
	EABI_LINUX		= 0x03,
	EABI_HURD		= 0x04,
	EABI_SOLARIS	= 0x06,
	EABI_AIX		= 0x07,
	EABI_IRIX		= 0x08,
	EABI_FREEBSD	= 0x09,
	EABI_TRU64		= 0x0A,
	EABI_MODESTO	= 0x0B,
	EABI_OPENBSD	= 0x0C,
	EABI_OPENVMS	= 0x0D,
	EABI_NSK		= 0x0E,
	EABI_AROS		= 0x0F,
	EABI_FENIXOS	= 0x10,
	EABI_CLOUDABI	= 0x11,
	EABI_OPENVOS	= 0x12,
};

enum	ELF_ExType
{
	ET_NONE		= 0x00,
	ET_REL		= 0x01,
	ET_EXEC		= 0x02,
	ET_DYN		= 0x03,
	ET_CORE		= 0x04,
	ET_LOOS		= 0xFE00,
	ET_HIOS		= 0xFEFF,
	ET_LOPROC	= 0xFF00,
	ET_HIPROC	= 0xFFFF
};

enum	ELF_Machine
{
    EM_NONE        = 0x00,
    EM_M32         = 0x01,
    EM_SPARC       = 0x02,
    EM_386         = 0x03,
    EM_68K         = 0x04,
    EM_88K         = 0x05,
    EM_IAMCU       = 0x06,
    EM_860         = 0x07,
    EM_MIPS        = 0x08,
    EM_ARM         = 0x28,
    EM_X86_64      = 0x3E,
	EM_AARCH64     = 0xB7,
    EM_RISCV       = 0xF3,
};

enum	ELF_Version
{
	EV_NONE		=	0x00,
	EV_CURRENT	=	0x01,
	EV_NUM		=	0x02,
};

enum	ELF_ProgType
{
	PT_NULL			= 0x00000000,
	PT_LOAD			= 0x00000001,
	PT_DYNAMIC		= 0x00000002,
	PT_INTERP		= 0x00000003,
	PT_NOTE			= 0x00000004,
	PT_SHLIB		= 0x00000005,
	PT_PHDR			= 0x00000006,
	PT_TLS			= 0x00000007,
	PT_LOOS			= 0x60000000,
	PT_GNU_EH_FRAME	= 0x6474e550,
	PT_GNU_STACK	= 0x6474e551,
	PT_GNU_RELRO	= 0x6474e552,
	PT_GNU_PROPERTY	= 0x6474e553,
	PT_LOSUNW		= 0x6ffffffa,
	PT_SUNWBSS		= 0x6ffffffa,
	PT_SUNWSTACK	= 0x6ffffffb,
	PT_HISUNW		= 0x6fffffff,
	PT_HIOS			= 0x6FFFFFFF,
	PT_LOPROC		= 0x70000000,
	PT_HIPROC		= 0x7FFFFFFF,
};

enum	ELF_ProgFlags
{
	PF_X		= (1 << 0),
	PF_W	= (1 << 1),
	PF_R		= (1 << 2),
	PF_MASKOS	= 0x0FF00000,
	PF_MASKPROC	= 0xF0000000,
};

enum	ELF_SectionType
{
	SHT_NULL			= 0x0,
	SHT_PROGBITS		= 0x1,
	SHT_SYMTAB			= 0x2,
	SHT_STRTAB			= 0x3,
	SHT_RELA			= 0x4,
	SHT_HASH			= 0x5,
	SHT_DYNAMIC			= 0x6,
	SHT_NOTE			= 0x7,
	SHT_NOBITS			= 0x8,
	SHT_REL				= 0x9,
	SHT_SHLIB			= 0x0A,
	SHT_DYNSYM			= 0x0B,
	SHT_INIT_ARRAY		= 0x0E,
	SHT_FINI_ARRAY		= 0x0F,
	SHT_PREINIT_ARRAY	= 0x10,
	SHT_GROUP			= 0x11,
	SHT_SYMTAB_SHNDX	= 0x12,
	SHT_NUM				= 0x13,
	SHT_LOOS			= 0x60000000,
	SHT_GNU_VERSYM		= 0x6FFFFFF0,
	SHT_GNU_HASH		= 0x6FFFFFF6,
	SHT_GNU_LIBLIST		= 0x6FFFFFF7,
	SHT_GNU_VERDEF		= 0x6FFFFFFD,
	SHT_GNU_VERNEED		= 0x6FFFFFFE,
	SHT_HIOS			= 0xFFFFFFFF,
};

enum	ELF_SectionFlags
{
	SHF_WRITE				= 0x1,
	SHF_ALLOC				= 0x2,
	SHF_EXECINSTR			= 0x4,
	SHF_MERGE				= 0x10,
	SHF_STRINGS				= 0x20,
	SHF_INFO_LINK			= 0x40,
	SHF_LINK_ORDER			= 0x80,
	SHF_OS_NONCONFORMING	= 0x100,
	SHF_GROUP				= 0x200,
	SHF_TLS					= 0x400,
	SHF_MASKOS				= 0x0FF00000,
	SHF_MASKPROC			= 0xF0000000,
	SHF_ORDERED				= 0x4000000,
	SHF_EXCLUDE				= 0x8000000,
	SHF_SOLARIS				= 0x80000000,
};

enum	ELF_SymbolVisibility
{
	STV_DEFAULT		= 0,
	STV_INTERNAL	= 1,
	STV_HIDDEN		= 2,
	STV_PROTECTED	= 3,
};

enum	ELF_SymbolBind
{
	STB_LOCAL		= 0,
	STB_GLOBAL		= 1,
	STB_WEAK		= 2,
	STB_NUM			= 3,
	STB_LOOS		= 10,
	STB_GNU_UNIQUE	= 10,
	STB_HIOS		= 12,
	STB_LOPROC		= 13,
	STB_HIPROC		= 15, 
};

enum	ELF_SymbolType
{
	STT_NOTYPE		= 0,
	STT_OBJECT		= 1,
	STT_FUNC		= 2,
	STT_SECTION		= 3,
	STT_FILE		= 4,
	STT_COMMON		= 5,
	STT_TLS			= 6,
	STT_NUM			= 7,
	STT_LOOS		= 10,
	STT_GNU_IFUNC	= 10,
	STT_HIOS		= 12,
	STT_LOPROC		= 13,
	STT_HIPROC		= 15,
};

enum	ELF_SectionIndices
{
	SHN_UNDEF		= 0,
	SHN_LORESERVE	= 0xFF00,
	SHN_LOPROC		= 0xFF00,
	SHN_BEFORE		= 0xFF00,
	SHN_AFTER		= 0xFF01,
	SHN_HIPROC		= 0xFF1F,
	SHN_ABS			= 0xFFF1,
	SHN_COMMON		= 0xFFF2,
	SHN_HIRESERVE	= 0xFFFF,
};

enum	ELF_DynamicTag
{
	DT_NULL				= 0,
	DT_NEEDED			= 1,
	DT_PLTRELSZ			= 2,
	DT_PLTGOT			= 3,
	DT_HASH				= 4,
	DT_STRTAB			= 5,
	DT_SYMTAB			= 6,
	DT_RELA				= 7,
	DT_RELASZ			= 8,
	DT_RELAENT			= 9,
	DT_STRSZ			= 10,
	DT_SYMENT			= 11,
	DT_INIT				= 12,
	DT_FINI				= 13,
	DT_SONAME			= 14,
	DT_RPATH			= 15,
	DT_SYMBOLIC			= 16,
	DT_REL				= 17,
	DT_RELSZ			= 18,
	DT_RELENT			= 19,
	DT_PLTREL			= 20,
	DT_DEBUG			= 21,
	DT_TEXTREL			= 22,
	DT_JMPREL			= 23,
	DT_BIND_NOW			= 24,
	DT_INIT_ARRAY		= 25,
	DT_FINI_ARRAY		= 26,
	DT_INIT_ARRAYSZ		= 27,
	DT_FINI_ARRAYSZ		= 28,
	DT_RUNPATH			= 29,
	DT_FLAGS			= 30,
	DT_ENCODING			= 32,
	DT_PREINIT_ARRAY	= 32,
	DT_PREINIT_ARRAYSZ	= 33,
	DT_SYMTAB_SHNDX		= 34,
	DT_NUM				= 35,
	DT_LOOS				= 0x6000000d,
	DT_HIOS				= 0x6ffff000,
	DT_LOPROC			= 0x70000000,
	DT_HIPROC			= 0x7fffffff
};

# else

/**
 * @enum	ELF_IdentIndices
 */
#  define	ELF_IdentIndicesList(X)											\
	X(EI_MAG0,			0)													\
	X(EI_MAG1,			1)													\
	X(EI_MAG2,			2)													\
	X(EI_MAG3,			3)													\
	X(EI_CLASS,			4)													\
	X(EI_DATA,			5)													\
	X(EI_VERSION,		6)													\
	X(EI_OSABI,			7)													\
	X(EI_ABIVERSION,	8)													\

#  define	ENUM_TYPE	ELF_IdentIndices
#  define	ENUM_LIST	ELF_IdentIndicesList
#  include	<sys/stringify.h>

/**
 * @enum	ELF_Class
 */
#  define	ELF_ClassList(X)												\
	X(ELF_32BIT,	0x01)													\
	X(ELF_64BIT,	0x02)													\

#  define	ENUM_TYPE	ELF_Class
#  define	ENUM_LIST	ELF_ClassList
#  include	<sys/stringify.h>

/**
 * @enum	ELF_Endianness
 */
#  define	ELF_EndiannessList(X)											\
	X(ELF_DATANONE,	0x00)													\
	X(ELF_DATA2LSB,	0x01)													\
	X(ELF_DATA2MSB,	0x02)													\

#  define	ENUM_TYPE	ELF_Endianness
#  define	ENUM_LIST	ELF_EndiannessList
#  include	<sys/stringify.h>

/**
 * @enum	ELF_OsAbi
 */
#  define	ELF_OsAbiList(X)												\
	X(EABI_SYSV,		0x00)												\
	X(EABI_HPUX,		0x01)   											\
	X(EABI_NETBSD,		0x02)   											\
	X(EABI_LINUX,		0x03)   											\
	X(EABI_HURD,		0x04)   											\
	X(EABI_SOLARIS,		0x06)   											\
	X(EABI_AIX,			0x07)   											\
	X(EABI_IRIX,		0x08)   											\
	X(EABI_FREEBSD,		0x09)   											\
	X(EABI_TRU64,		0x0A)   											\
	X(EABI_MODESTO,		0x0B)   											\
	X(EABI_OPENBSD,		0x0C)   											\
	X(EABI_OPENVMS,		0x0D)   											\
	X(EABI_NSK,			0x0E)   											\
	X(EABI_AROS,		0x0F)   											\
	X(EABI_FENIXOS,		0x10)   											\
	X(EABI_CLOUDABI,	0x11)   											\
	X(EABI_OPENVOS,		0x12)												\

#  define	ENUM_TYPE	ELF_OsAbi
#  define	ENUM_LIST	ELF_OsAbiList
#  include	<sys/stringify.h>

/**
 * @enum	ELF_ExType
 */
#  define	ELF_ExTypeList(X)												\
	X(ET_NONE,		0x00)													\
	X(ET_REL,		0x01)													\
	X(ET_EXEC,		0x02)													\
	X(ET_DYN,		0x03)													\
	X(ET_CORE,		0x04)													\
	X(ET_LOOS,		0xFE00)													\
	X(ET_HIOS,		0xFEFF)													\
	X(ET_LOPROC,   	0xFF00)													\
	X(ET_HIPROC,   	0xFFFF)													\

#  define	ELF_ExTypeSpec(X)												\
	X((ENUM_VAR >= ET_LOOS && ENUM_VAR <= ET_HIOS), "ET_OS_SPECIFIC")		\
	X((ENUM_VAR >= ET_LOPROC), "ET_PROCESSOR_SPECIFIC")						\

#  define	ENUM_TYPE	ELF_ExType
#  define	ENUM_LIST	ELF_ExTypeList
#  define	ENUM_SPEC	ELF_ExTypeSpec
#  include	<sys/stringify.h>

/**
 * @enum	ELF_Machine
 */
#  define	ELF_MachineList(X)												\
	X(EM_NONE,		0x00)													\
	X(EM_M32,		0x01)													\
	X(EM_SPARC,		0x02)													\
	X(EM_386,		0x03)													\
	X(EM_68K,		0x04)													\
	X(EM_88K,		0x05)													\
	X(EM_IAMCU,		0x06)													\
	X(EM_860,		0x07)													\
	X(EM_MIPS,		0x08)													\
	X(EM_ARM,		0x28)													\
	X(EM_X86_64,	0x3E)													\
	X(EM_AARCH64,	0xB7)													\
	X(EM_RISCV,		0xF3)													\

#  define	ENUM_TYPE	ELF_Machine
#  define	ENUM_LIST	ELF_MachineList
#  include	<sys/stringify.h>

/**
 * @enum	ELF_Version
 */
#  define	ELF_VersionList(X)												\
	X(EV_NONE,			0x00)												\
	X(EV_CURRENT,		0x01)												\
	X(EV_NUM,			0x02)												\

#  define	ENUM_TYPE	ELF_Version
#  define	ENUM_LIST	ELF_VersionList
#  include	<sys/stringify.h>

/**
 * @enum	ELF_ProgType
 */
#  define	ELF_ProgTypeList(X)												\
	X(PT_NULL,			0x00000000)											\
	X(PT_LOAD,			0x00000001)											\
	X(PT_DYNAMIC,		0x00000002)											\
	X(PT_INTERP,		0x00000003)											\
	X(PT_NOTE,			0x00000004)											\
	X(PT_SHLIB,			0x00000005)											\
	X(PT_PHDR,			0x00000006)											\
	X(PT_TLS,			0x00000007)											\
	X(PT_LOOS,			0x60000000)											\
	X(PT_GNU_EH_FRAME,	0x6474e550)											\
	X(PT_GNU_STACK,		0x6474e551)											\
	X(PT_GNU_RELRO,		0x6474e552)											\
	X(PT_GNU_PROPERTY,	0x6474e553)											\
	X(PT_HIOS,			0x6FFFFFFF)											\
	X(PT_LOPROC,		0x70000000)											\
	X(PT_HIPROC,		0x7FFFFFFF)											\

#  define	ELF_ProgTypeSpec(X)												\
	X(((ENUM_VAR >= PT_LOOS &&	ENUM_VAR < PT_GNU_EH_FRAME)	||				\
			(ENUM_VAR > PT_GNU_PROPERTY && ENUM_VAR <= PT_HIOS)				\
			), "PT_OS_SPECIFIC")											\
	X((ENUM_VAR >= PT_LOPROC && ENUM_VAR <= PT_HIPROC						\
			), "PT_PROCESSOR_SPECIFIC")										\

#  define	ENUM_TYPE	ELF_ProgType
#  define	ENUM_LIST	ELF_ProgTypeList
#  define	ENUM_SPEC	ELF_ProgTypeSpec
#  include	<sys/stringify.h>

/**
 * @enum	ELF_ProgFlags
 */
#  define	ELF_ProgFlagsList(X)											\
	X(PF_X,			(1<<0))													\
	X(PF_W,			(1<<1))													\
	X(PF_R,			(1<<2))													\
	X(PF_MASKOS,	0x0FF00000)												\
	X(PF_MASKPROC,	0xF0000000)												\

#  define	ENUM_TYPE	ELF_ProgFlags
#  define	ENUM_LIST	ELF_ProgFlagsList
#  include	<sys/stringify.h>

/**
 * @enum	ELF_SectionType
 */
#  define	ELF_SectionTypeList(X)											\
	X(SHT_NULL,				0x0)											\
	X(SHT_PROGBITS,			0x1)											\
	X(SHT_SYMTAB,			0x2)											\
	X(SHT_STRTAB,			0x3)											\
	X(SHT_RELA,				0x4)											\
	X(SHT_HASH,				0x5)											\
	X(SHT_DYNAMIC,			0x6)											\
	X(SHT_NOTE,				0x7)											\
	X(SHT_NOBITS,			0x8)											\
	X(SHT_REL,				0x9)											\
	X(SHT_SHLIB,			0x0A)											\
	X(SHT_DYNSYM,			0x0B)											\
	X(SHT_INIT_ARRAY,		0x0E)											\
	X(SHT_FINI_ARRAY,		0x0F)											\
	X(SHT_PREINIT_ARRAY,	0x10)											\
	X(SHT_GROUP,			0x11)											\
	X(SHT_SYMTAB_SHNDX,		0x12)											\
	X(SHT_NUM,				0x13)											\
	X(SHT_LOOS,				0x60000000)										\
	X(SHT_GNU_VERSYM,		0x6FFFFFF0)										\
	X(SHT_GNU_HASH,			0x6FFFFFF6)										\
	X(SHT_GNU_LIBLIST,		0x6FFFFFF7)										\
	X(SHT_GNU_VERDEF,		0x6FFFFFFD)										\
	X(SHT_GNU_VERNEED,		0x6FFFFFFE)										\
	X(SHT_HIOS,				0xFFFFFFFF)										\

#  define	ELF_SectionTypeSpec(X)											\
	X(((ENUM_VAR >= SHT_LOOS && ENUM_VAR < SHT_GNU_VERSYM) ||				\
			(ENUM_VAR > SHT_GNU_VERNEED && ENUM_VAR <= SHT_HIOS)			\
			), "SHT_OS_SPECIFIC")											\

#  define	ENUM_TYPE	ELF_SectionType
#  define	ENUM_LIST	ELF_SectionTypeList
#  define	ENUM_SPEC	ELF_SectionTypeSpec
#  include	<sys/stringify.h>

/**
 * @enum	ELF_SectionFlags
 */
#  define	ELF_SectionFlagsList(X)											\
	X(SHF_WRITE,			0x1)											\
	X(SHF_ALLOC,			0x2)											\
	X(SHF_EXECINSTR,		0x4)											\
	X(SHF_MERGE,			0x10)											\
	X(SHF_STRINGS,			0x20)											\
	X(SHF_INFO_LINK,		0x40)											\
	X(SHF_LINK_ORDER,		0x80)											\
	X(SHF_OS_NONCONFORMING,	0x100)											\
	X(SHF_GROUP,			0x200)											\
	X(SHF_TLS,				0x400)											\
	X(SHF_MASKOS,			0x0FF00000)										\
	X(SHF_MASKPROC,			0xF0000000)										\
	X(SHF_ORDERED,			0x4000000)										\
	X(SHF_EXCLUDE,			0x800000)										\
	X(SHF_SOLARIS,			0x80000000)										\

#  define	ENUM_TYPE	ELF_SectionFlags
#  define	ENUM_LIST	ELF_SectionFlagsList
#  include	<sys/stringify.h>

/**
 * @enum	ELF_SymbolVisibility
 */
#  define	ELF_SymbolVisibilityList(X)										\
	X(STV_DEFAULT,		0)													\
	X(STV_INTERNAL,		1)													\
	X(STV_HIDDEN,		2)													\
	X(STV_PROTECTED,	3)													\

#  define	ENUM_TYPE	ELF_SymbolVisibility
#  define	ENUM_LIST	ELF_SymbolVisibilityList
#  include	<sys/stringify.h>

/**
 * @enum	ELF_SymbolBind
 */
#  define	ELF_SymbolBindList(X)											\
	X(STB_LOCAL,		0)													\
	X(STB_GLOBAL,		1)													\
	X(STB_WEAK,			2)													\
	X(STB_NUM,			3)													\
	X(STB_LOOS,			10)													\
	X(STB_GNU_UNIQUE,	10)													\
	X(STB_HIOS,			12)													\
	X(STB_LOPROC,		13)													\
	X(STB_HIPROC,		15)													\

#  define	ENUM_TYPE	ELF_SymbolBind
#  define	ENUM_LIST	ELF_SymbolBindList
#  include	<sys/stringify.h>

/**
 * @enum	ELF_SymbolType
 */
#  define	ELF_SymbolTypeList(X)											\
	X(STT_NOTYPE,		0)													\
	X(STT_OBJECT,		1)													\
	X(STT_FUNC,			2)													\
	X(STT_SECTION,		3)													\
	X(STT_FILE,			4)													\
	X(STT_COMMON,		5)													\
	X(STT_TLS,			6)													\
	X(STT_NUM,			7)													\
	X(STT_GNU_IFUNC,	10)													\
	X(STT_LOOS,			10)													\
	X(STT_HIOS,			12)													\
	X(STT_LOPROC,		13)													\
	X(STT_HIPROC,		15)													\

#  define	ENUM_TYPE	ELF_SymbolType
#  define	ENUM_LIST	ELF_SymbolTypeList
#  include	<sys/stringify.h>

/**
 * @enum	ELF_SectionIndices
 */
#  define	ELF_SectionIndicesList(X)										\
	X(SHN_UNDEF,		0)													\
	X(SHN_LORESERVE,	0xFF00)												\
	X(SHN_LOPROC,		0xFF00)												\
	X(SHN_BEFORE,		0xFF00)												\
	X(SHN_AFTER,		0xFF01)												\
	X(SHN_HIPROC,		0xFF1F)												\
	X(SHN_ABS,			0xFFF1)												\
	X(SHN_COMMON,		0xFFF2)												\
	X(SHN_HIRESERVE,	0xFFFF)												\

#  define	ENUM_TYPE	ELF_SectionIndices
#  define	ENUM_LIST	ELF_SectionIndicesList
#  include	<sys/stringify.h>

/**
 * @enum	ELF_DynamicTag
 */

#  define	ELF_DynamicTagList(X)											\
	X(DT_NULL,				0)												\
	X(DT_NEEDED,			1)												\
	X(DT_PLTRELSZ,			2)												\
	X(DT_PLTGOT,			3)												\
	X(DT_HASH,				4)												\
	X(DT_STRTAB,			5)												\
	X(DT_SYMTAB,			6)												\
	X(DT_RELA,				7)												\
	X(DT_RELASZ,			8)												\
	X(DT_RELAENT,			9)												\
	X(DT_STRSZ,				10)												\
	X(DT_SYMENT,			11)												\
	X(DT_INIT,				12)												\
	X(DT_FINI,				13)												\
	X(DT_SONAME,			14)												\
	X(DT_RPATH,				15)												\
	X(DT_SYMBOLIC,			16)												\
	X(DT_REL,				17)												\
	X(DT_RELSZ,				18)												\
	X(DT_RELENT,			19)												\
	X(DT_PLTREL,			20)												\
	X(DT_DEBUG,				21)												\
	X(DT_TEXTREL,			22)												\
	X(DT_JMPREL,			23)												\
	X(DT_BIND_NOW,			24)												\
	X(DT_INIT_ARRAY,		25)												\
	X(DT_FINI_ARRAY,		26)												\
	X(DT_INIT_ARRAYSZ,		27)												\
	X(DT_FINI_ARRAYSZ,		28)												\
	X(DT_RUNPATH,			29)												\
	X(DT_FLAGS,				30)												\
	X(DT_ENCODING,			32)												\
	X(DT_PREINIT_ARRAY,		32)												\
	X(DT_PREINIT_ARRAYSZ,	33)												\
	X(DT_SYMTAB_SHNDX,		34)												\
	X(DT_NUM,				35)												\
	X(DT_LOOS,				0x6000000d)										\
	X(DT_HIOS,				0x6ffff000)										\
	X(DT_LOPROC,			0x70000000)										\
	X(DT_HIPROC,			0x7fffffff)										\

#  define	ELF_DynamicTagSpec(X)											\
	X((ENUM_VAR >= DT_LOOS && ENUM_VAR <= DT_HIOS), "OS_SPECIFIC")			\
	X((ENUM_VAR >= DT_LOPROC && ENUM_VAR <= DT_HIPROC), "PROC_SPECIFIC")	\

#  define ENUM_TYPE		ELF_DynamicTag
#  define ENUM_LIST		ELF_DynamicTagList
#  define ENUM_SPEC		ELF_DynamicTagSpec
#  include	<sys/stringify.h>

# endif	// ELF_ENUMS_STRINGIFY

#endif	// __ELF_IDENTIFIER_H__
