CC = clang
AR = ar
# Define compiler and linker flags
CFLAGS = -O3
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -MMD -MP -m64
PIC_FLAGS = -fPIC

# Define linker flags and version script
# CFLAGS += -fvisibility=hidden
LDFLAGS += -nostartfiles -nodefaultlibs

ifeq ($(VERSIONNING), true)
	VERSIONNING_CONF = $(shell realpath config/Version.v)
	LDFLAGS += -Wl,--version-script=$(VERSIONNING_CONF) -v
endif

AS = nasm
NASM_FLAGS = -g -F dwarf -I $(INCLUDE_DIR)
