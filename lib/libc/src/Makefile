FOLDER_LIST := $(shell find . -maxdepth 1 -mindepth 1 -type d -printf "%f\n")
ARCHIVES := $(foreach folder,$(FOLDER_LIST),$(BUILD_FOLDER)/$(folder)/$(folder).a)
STAMP_FILES := $(foreach folder,$(FOLDER_LIST),$(BUILD_FOLDER)/$(folder)/.stamp)

all: $(BUILD_NAME)

# Rule: build per-folder .stamp file
$(BUILD_FOLDER)/%/.stamp:
	@echo ">>> Building subfolder '$*'"
	$(MAKE) -C $* \
		BUILD_FOLDER="$(BUILD_FOLDER)/$*" \
		ARCHIVE_NAME="$(BUILD_FOLDER)/$*/$*.a"
	touch $@

# Rule: .stamp depends on .c files of its folder
define folder_deps
$(BUILD_FOLDER)/$1/.stamp: $$(shell find $1 -name '*.c')
endef

$(foreach folder,$(FOLDER_LIST),$(eval $(call folder_deps,$(folder))))

# Final archive rule
$(BUILD_NAME): $(STAMP_FILES)
	@echo ">>> Packing final archive: $@"
	rm -f $@
	for archive in $(ARCHIVES); do $(AR) x $$archive; done
	$(AR) rcs $(AR_FLAGS) $@ *.o
	rm *.o

clean:
	rm -rf $(BUILD_FOLDER) $(BUILD_NAME)

.PHONY: all clean
