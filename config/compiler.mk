CC = clang
# Define compiler and linker flags
CFLAGS = -O3 -mavx2 -masm=intel -mtune=native
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -MMD -MP -m64
PIC_FLAGS = -fPIC

# Define linker flags and version script
# CFLAGS += -fvisibility=hidden
LDFLAGS += -nostartfiles -nodefaultlibs

ifeq ($(VERSIONNING), true)
	LDFLAGS += -Wl,--version-script=config/Version.v -v
endif

AS = nasm
NASM_FLAGS = -g -F dwarf -I $(INCLUDE_DIR)

AR = ar

