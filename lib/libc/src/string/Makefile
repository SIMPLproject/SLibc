# ─────────────────────────────────────────────────────────────
# Function Folder Structure Requirements
#
# Each function must follow this structure:
#
# • Be placed in a folder named after the function (e.g., "foo/")
#
# • Contain the following files:
#   - foo_config.c     → Handles IFUNC, weak aliases, etc.
#   - foo_generic.c    → Base version without optimizations (fallback)
#   - foo_template.c   → Optimized version, compiled multiple times
#                        depending on the target CPU architecture
# ─────────────────────────────────────────────────────────────
FUNC_LIST=$(shell find . -maxdepth 1 -mindepth 1 -type d -printf "%f ")

# Build per-function static archives
FUNC_ARCHIVES := $(foreach func, $(FUNC_LIST), $(BUILD_FOLDER)/$(func)/$(func).a)

# $(info ARCHIVES = $(FUNC_ARCHIVES))

# Final combined archive
$(ARCHIVE_NAME): $(FUNC_ARCHIVES)
	@echo "Packing final archive: $@"
	rm -f $@
	for archive in $^; do $(AR) x $$archive; done
	$(AR) rcs $(AR_FLAG) $@ *.o
	rm *.o

# Archive rule per function
define GEN_FUNC_ARCHIVE
$(BUILD_FOLDER)/$1/$1.a: \
  $(BUILD_FOLDER)/$1/$1_generic.o \
  $(BUILD_FOLDER)/$1/$1_config.o \
  $(foreach flag,$(VERSION_FLAGS),$(BUILD_FOLDER)/$1/$1_template_$(flag).o)
	@echo "Archiving $$@"
	@$(AR) rcs $(AR_FLAG) $$@ $$^
endef

# Object rules: default & config
define GEN_FUNC_OBJECT_RULES
$(BUILD_FOLDER)/$1/$1_generic.o: $1/$1_generic.c
	@mkdir -p $$(dir $$@)
	$$(CC) $$(CFLAGS) $$(DISABLE_VECTORISE) $$(BASE_INCLUDE) -c $$< -o $$@

$(BUILD_FOLDER)/$1/$1_config.o: $1/$1_config.c
	@mkdir -p $$(dir $$@)
	$$(CC) $$(CFLAGS) $$(DISABLE_VECTORISE) $$(BASE_INCLUDE) $$(CONFIG_INCLUDE) -c $$< -o $$@
endef

# SIMD object rules per flag
define GEN_SIMD_OBJECT_RULE
$(BUILD_FOLDER)/$1/$1_template_$2.o: $1/$1_template.c
	@mkdir -p $$(dir $$@)
	$$(CC) $$(CFLAGS) -m$2 $$(BASE_INCLUDE) $$(CONFIG_INCLUDE) -c $$< -o $$@
endef

# Emit all rules
$(foreach func,$(FUNC_LIST), \
  $(eval $(call GEN_FUNC_ARCHIVE,$(func))) \
  $(eval $(call GEN_FUNC_OBJECT_RULES,$(func))) \
  $(foreach flag,$(VERSION_FLAGS), \
    $(eval $(call GEN_SIMD_OBJECT_RULE,$(func),$(flag))) \
  ) \
)

.PHONY: clean
clean:
	rm -rf $(BUILD_FOLDER) $(ARCHIVE_NAME)
