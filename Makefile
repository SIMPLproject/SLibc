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
CFLAGS := -Wall -Wextra -O3 -MMD -MP -fPIC -g
DISABLE_VECTORISE := -fno-tree-vectorize -fno-builtin -mno-sse -mno-avx
VERSION_FLAGS := sse4 avx2


CONFIG_INCLUDE := -I $(shell realpath lib/config)
BASE_INCLUDE := -I $(BUILD_INCLUDE_FOLDER)
$(info include $(BUILD_INCLUDE_FOLDER))

export CC
export AR
export AR_FLAGS
export CFLAGS
export DISABLE_VECTORISE
export VERSION_FLAGS
export BASE_INCLUDE
export CONFIG_INCLUDE
export SYSTEM
export ARCH
##############################################################################################

LIBS_SRC = $(addprefix lib/,$($(LIBS)_NAME))
$(info $(SYSDEPS_BITS))

all : init_build include crt libs_archive custom_clang libs_shared


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
		ARCHIVE_NAME="$(BUILD_LIB_FOLDER)/$(1).a"
endef

# Define a function to build the shared library.
# $(1) lib name
# $(2) abi version
define build_shared
	$(CC) -nostdlib -shared -o $(BUILD_LIB_FOLDER)/$(1).so.$(2) \
		-Wl,--whole-archive $(BUILD_LIB_FOLDER)/$(1).a -Wl,--no-whole-archive \
		-Wl,-soname,$(1).so.$(2) $(LDFLAGS)
	ln -sf $(1).so.$(2) $(BUILD_LIB_FOLDER)/$(1).so
endef

# ----------------------------------------------------------------------------
# The target that builds the static archives.
libs_archive: init_build include
	$(foreach lib,$(LIBS), $(call build_archive,$($(lib)_NAME)))

# The target that builds the shared libraries; depends on static archives.
libs_shared: libs_archive
	$(foreach lib, $(LIBS), $(call build_shared,$($(lib)_NAME),$($(lib)_ABI_VERSION)))

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
