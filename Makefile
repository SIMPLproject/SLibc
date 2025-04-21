SYSTEM=linux
ARCH=x86_64
BUILD_FOLDER=$(shell realpath bin)

MK_CONFIG=$(shell realpath config)
-include $(MK_CONFIG)/*.mk
export MK_CONFIG

# to rm in config folder
##############################################################################################
CC := clang
AR = ar
AR_FLAGS = 
CFLAGS = -Wall -Wextra -O0 -MMD -MP -fPIC -g 

CFLAGS +=  -fno-stack-protector -fno-pie -mno-red-zone -nostdlib -ffreestanding

VERSION_FLAGS = sse4 avx2

SINGLE_THREAD = true

ifdef NATIVE
SIMD_LEVEL := -m$(NATIVE)
else
SIMD_LEVEL := -fno-tree-vectorize -fno-builtin -mno-sse -mno-avx
endif

# for the compile_commands.json
CFLAGS += -nostdinc

CONFIG_INCLUDE := -I $(shell realpath lib/config)
BASE_INCLUDE := -I $(BUILD_INCLUDE_FOLDER)
$(info include $(BUILD_INCLUDE_FOLDER))

export CC
export AR
export AR_FLAGS
export CFLAGS
export SIMD_LEVEL
export VERSION_FLAGS
export BASE_INCLUDE
export CONFIG_INCLUDE
export SYSTEM
export ARCH
##############################################################################################

LIBS_SRC = $(addprefix lib/,$($(LIBS)_NAME))
$(info $(SYSDEPS_BITS))

all : init_build include crt  custom_clang build_libs


# init phase
##############################################################################################
SYSDEPS_BITS = $(shell find $(LIBS_SRC) -type d -wholename '*/sysdeps/$(SYSTEM)/$(ARCH)/bits')

init_build: 
	mkdir -p $(BUILD_FOLDER)
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
# all lib settings are in config/lib.mk
$(info LIBS = $(LIBS))

# $(1) lib name
define build_archive
	echo $(1)
	$(MAKE) -C lib/$(1) \
		BUILD_FOLDER="$(BUILD_OBJ_FOLDER)/$(1)" \
		LIB_FOLDER="$(BUILD_LIB_FOLDER)" \
		NAME="$(1)"
endef

build_libs: init_build include
	$(foreach lib,$(LIBS), $(call build_archive,$($(lib)_NAME)))

##############################################################################################



# crt (start and fini file for .so lib)
##############################################################################################

crt:  include $(BUILD_LIB_FOLDER)/crt1.o  $(BUILD_LIB_FOLDER)/crti.o  $(BUILD_LIB_FOLDER)/crtn.o 

CRT_CFLAGS = -fno-pie -nostdlib
$(BUILD_LIB_FOLDER)/crt1.o : crt/$(SYSTEM)/$(ARCH)/crt1.c
	$(CC) $(CRT_CFLAGS) -c $< -o $@

$(BUILD_LIB_FOLDER)/crti.o : crt/$(SYSTEM)/$(ARCH)/crti.c
	$(CC) $(CRT_CFLAGS) -c $< -o $@
	
$(BUILD_LIB_FOLDER)/crtn.o : crt/$(SYSTEM)/$(ARCH)/crtn.c
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
clean:
	rm -rf $(BUILD_OBJ_FOLDER)

fclean:
	rm -rf $(BUILD_FOLDER)

re: fclean all

.PHONY: all clean fclean re init_build include
##############################################################################################
