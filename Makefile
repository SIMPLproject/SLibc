SYSTEM=linux
ARCH=x86_64
BUILD_FOLDER=$(shell realpath bin)

MK_CONFIG=$(shell realpath config)
-include $(MK_CONFIG)/*.mk
export MK_CONFIG

##############################################################################################
# to rm in config folder
CC := clang
AR = ar
AR_FLAGS = 
CFLAGS := -Wall -Wextra -O3 -MMD -MP -fPIC
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

LIBS = libc
LIBS_SRC = $(addprefix lib/,$(LIBS))
SYSDEPS_BITS = $(shell find $(LIBS_SRC) -type d -wholename '*/sysdeps/$(SYSTEM)/$(ARCH)/bits')
$(info $(SYSDEPS_BITS))

all : init_build include crt libs

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

libs: init_build include
	for lib in $(LIBS); do \
		make -C lib/$$lib \
			BUILD_FOLDER="$(BUILD_OBJ_FOLDER)/$$lib" \
			ARCHIVE_NAME="$(BUILD_LIB_FOLDER)/$${lib}.so" ; \
	done


CRT_CFLAGS = -fno-pie -nostdlib
$(BUILD_LIB_FOLDER)/crt1.o : crt/$(SYSTEM)/$(ARCH)/crt1.c
	$(CC) $(CRT_CFLAGS) -c $< -o $@

$(BUILD_LIB_FOLDER)/crti.o : crt/$(SYSTEM)/$(ARCH)/crti.c
	$(CC) $(CRT_CFLAGS) -c $< -o $@
	
$(BUILD_LIB_FOLDER)/crtn.o : crt/$(SYSTEM)/$(ARCH)/crtn.c
	$(CC) $(CRT_CFLAGS) -c $< -o $@

crt:  include $(BUILD_LIB_FOLDER)/crt1.o  $(BUILD_LIB_FOLDER)/crti.o  $(BUILD_LIB_FOLDER)/crtn.o 

clean:
	rm -rf $(BUILD_OBJ_FOLDER)

fclean:
	rm -rf $(BUILD_FOLDER)

re: fclean all

.PHONY: all clean fclean re init_build include
