# === Configuration ===
BUILD_FOLDER_RELATIF=../oui
BUILD_FOLDER=$(shell realpath ../oui)
LIBC_SRC_ARCHIVE := $(BUILD_FOLDER)/libc_src.a

FOLDER_LIST := $(shell find . -maxdepth 1 -mindepth 1 -type d -printf "%f\n")

CC := clang
CFLAGS := -Wall -Wextra -O3
DISABLE_VECTORISE := -fno-tree-vectorize -fno-builtin -mno-sse -mno-avx
VERSION_FLAGS := sse4 avx2
BASE_INCLUDE := -I $(shell realpath ../../../include)
CONFIG_INCLUDE := -I $(shell realpath ../../config)

ARCHIVES := $(foreach folder,$(FOLDER_LIST),$(BUILD_FOLDER)/$(folder)/$(folder).a)
STAMP_FILES := $(foreach folder,$(FOLDER_LIST),$(BUILD_FOLDER)/$(folder)/.stamp)

all: $(LIBC_SRC_ARCHIVE)

# === Rule: build per-folder .stamp file ===
$(BUILD_FOLDER)/%/.stamp:
	@echo ">>> Building subfolder '$*'"
	$(MAKE) -C $* \
		CC="$(CC)" \
		CFLAGS="$(CFLAGS)" \
		DISABLE_VECTORISE="$(DISABLE_VECTORISE)" \
		VERSION_FLAGS="$(VERSION_FLAGS)" \
		BASE_INCLUDE="$(BASE_INCLUDE)" \
		CONFIG_INCLUDE="$(CONFIG_INCLUDE)" \
		BUILD_FOLDER="$(BUILD_FOLDER)/$*" \
		ARCHIVE_NAME="$(BUILD_FOLDER)/$*/$*.a"
	touch $@

# === Rule: .stamp depends on .c files of its folder ===
define folder_deps
$(BUILD_FOLDER)/$1/.stamp: $$(shell find $1 -name '*.c')
endef

$(foreach folder,$(FOLDER_LIST),$(eval $(call folder_deps,$(folder))))

# === Final archive rule ===
$(LIBC_SRC_ARCHIVE): $(STAMP_FILES)
	@echo ">>> Packing final archive: $@"
	rm -f $@
	for archive in $(ARCHIVES); do ar x $$archive; done
	ar rcs $@ $(ARCHIVES)
	rm *.o

# === Convenience ===
all: $(LIBC_SRC_ARCHIVE)

clean:
	rm -rf $(BUILD_FOLDER) $(LIBC_SRC_ARCHIVE)

.PHONY: all clean
