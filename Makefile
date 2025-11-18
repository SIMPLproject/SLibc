SYSTEM=linux
ARCH=x86_64
BUILD_FOLDER=$(shell realpath bin)
BASE_FOLDER=$(PWD)

MK_CONFIG=$(shell realpath config)
-include $(MK_CONFIG)/*.mk
export MK_CONFIG

# to rm in config folder
##############################################################################################

CC := clang
AR = ar
AR_FLAGS = 
CFLAGS = -Wall -Wextra -O0 -MMD -MP -fPIC -gdwarf-2 -g3 

CFLAGS +=  -fno-stack-protector  -mno-red-zone -nostdlib -ffreestanding

VERSION_FLAGS = sse4 avx2

SINGLE_THREAD = true

ifdef NATIVE
SIMD_LEVEL := -m$(NATIVE)
else
SIMD_LEVEL := -fno-tree-vectorize -fno-builtin -mno-sse -mno-avx
endif

# for the compile_commands.json
# CFLAGS += -nostdinc

ifeq ($(VERBOSE), true)
	CFLAGS += -DVERBOSE
endif

ifdef LIB
LIBS = $(LIB)
endif

CONFIG_INCLUDE := -I $(shell realpath lib/config)
BASE_INCLUDE := -I $(BUILD_INCLUDE_FOLDER)

CFLAGS += -DIN_libc

export CC
export AR
export AR_FLAGS
export CFLAGS
export SIMD_LEVEL
export VERSION_FLAGS
export BASE_INCLUDE
export CONFIG_INCLUDE
export BUILD_LIB_FOLDER
export SYSTEM
export ARCH



##############################################################################################

LIBS_SRC = $(addprefix lib/,$($(LIBS)_NAME))

all : setup libs

setup : init_build include crt  custom_clang


# init phase
##############################################################################################
SYSDEPS_BITS = $(shell find $(LIBS_SRC) -type d -wholename '*/sysdeps/$(SYSTEM)/$(ARCH)/bits')

init_build: 
	mkdir -p $(BUILD_FOLDER)
	rm -rf $(BUILD_INCLUDE_FOLDER)
	mkdir -p $(BUILD_INCLUDE_FOLDER)/bits
	mkdir -p $(BUILD_LIB_FOLDER)
	mkdir -p $(BUILD_OBJ_FOLDER)

include: init_build
	cp -r $(INCLUDE_FOLDER) $(BUILD_FOLDER)
	for dir in $(SYSDEPS_BITS); do \
		echo "cp $$dir/* -> $(BUILD_INCLUDE_FOLDER)/bits"; \
		cp -r $$dir/* $(BUILD_INCLUDE_FOLDER)/bits/; \
	done

##############################################################################################


# build lib
##############################################################################################

-include lib/lib.mk

##############################################################################################



# crt (start and fini file for .so lib)
##############################################################################################

crt:  include $(BUILD_LIB_FOLDER)/crt1.o  $(BUILD_LIB_FOLDER)/crti.o  $(BUILD_LIB_FOLDER)/crtn.o 

CRT_CFLAGS = -nostdlib
$(BUILD_LIB_FOLDER)/crt1.o : crt/$(SYSTEM)/$(ARCH)/crt1.S
	$(CC) $(CRT_CFLAGS) -c $< -o $@

$(BUILD_LIB_FOLDER)/crti.o : crt/$(SYSTEM)/$(ARCH)/crti.S
	$(CC) $(CRT_CFLAGS) -c $< -o $@
	
$(BUILD_LIB_FOLDER)/crtn.o : crt/$(SYSTEM)/$(ARCH)/crtn.S
	$(CC) $(CRT_CFLAGS) -c $< -o $@

##############################################################################################



# custom clang for shared object 
##############################################################################################
PATH := $(BUILD_FOLDER):$(PATH)

custom_clang : init_build
	cp config/sclang $(BUILD_FOLDER)/sclang
	echo "export PATH=$(BUILD_FOLDER):$$PATH" > $(BUILD_FOLDER)/clang_path
	echo "export SLIBC_PATH=$(BUILD_FOLDER)" >> $(BUILD_FOLDER)/clang_path
	chmod +x $(BUILD_FOLDER)/clang_path

##############################################################################################



# utils 
##############################################################################################
# $(1) lib name
define clean_lib
	@echo cleanning : $(1)
	rm -rf $(BUILD_LIB_FOLDER)/$(1)
	rm -rf $(BUILD_OBJ_FOLDER)/$(1)
	@echo end of cleanning $(1)
endef

clean: 
	$(foreach lib,$(LIBS), $(call clean_lib,$($(lib)_NAME)))

fclean:
	rm -rf $(BUILD_FOLDER)

re: clean all

.PHONY: all clean fclean re init_build include
##############################################################################################
