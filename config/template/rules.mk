ifdef NATIVE

# $(1) obj_name
# $(2) src
define OBJ_RULES
__SRC_$(1)_BASE := $$(filter-out %_simd.c,$(2))

$(1) = $$(patsubst %.c,$$(BUILD_FOLDER)/%.o,$$(__SRC_$(1)_BASE))
endef


else  # no NATIVE defined

# $(1) obj_name
# $(2) src
define OBJ_RULES
__SRC_$(1)_BASE := $$(filter-out %_build.c %_simd.c,$(2))
__SRC_$(1)_CONFIG := $$(filter %_build.c,$(2))
__SRC_$(1)_TEMPLATE := $$(filter %_simd.c,$(2))

$(1) = $$(patsubst %.c,$$(BUILD_FOLDER)/%.o,$$(__SRC_$(1)_BASE))
$(1) += $$(foreach flag,$$(VERSION_FLAGS),$$(patsubst %_simd.c,$$(BUILD_FOLDER)/%_$$(flag)_shared.o,$$(__SRC_$(1)_TEMPLATE)))
$(1) += $$(patsubst %.c,$$(BUILD_FOLDER)/%_archive.o,$$(__SRC_$(1)_CONFIG))
$(1) += $$(patsubst %.c,$$(BUILD_FOLDER)/%_shared.o,$$(__SRC_$(1)_CONFIG))
endef

endif

INCLUDE = $(BASE_INCLUDE) $(CONFIG_INCLUDE)

define TEMPLATE_RULES
$(BUILD_FOLDER)/%_$(1)_shared.o : %_simd.c
	mkdir -p $$(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -m$(1) -c $$< -o $$@
endef


$(foreach flag,$(VERSION_FLAGS),\
	$(info --- $(flag)) \
	$(info $(call TEMPLATE_RULES,$(flag)))\
	$(eval $(call TEMPLATE_RULES,$(flag)))\
)

$(BUILD_FOLDER)/%_build_shared.o : %_build.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(SIMD_LEVEL) $(INCLUDE) -DSHARED -c $< -o $@

$(BUILD_FOLDER)/%_build_archive.o : %_build.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(SIMD_LEVEL) $(INCLUDE) -DARCHIVE -c $< -o $@

$(BUILD_FOLDER)/%_build.o : %_build.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(SIMD_LEVEL) $(INCLUDE) -DNATIVE=$(NATIVE) -c $< -o $@

$(BUILD_FOLDER)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(SIMD_LEVEL) $(INCLUDE) -c $< -o $@

# $(1) lib name
# $(2) lib build folder
# $(3) OBJ
define COMPILE_LIB
compile_libs : $(2)/$(1).a $(2)/$(1).so

$$(eval OBJ_SHARED_$(1) := $$(filter-out %_archive.o,$(3)))
$$(eval OBJ_ARCHIVE_$(1) := $$(filter-out %_shared.o %_generic.o,$(3)))

$(2)/$(1).so: $$(OBJ_SHARED_$(1))
	$$(CC) -v -shared -Wl,-soname,$(1)  -Wl,-z,defs -Wl,--dynamic-linker=/lib64/ld-linux-x86-64.so.2 -nostdlib -o $$@ $$^  $$(LDFLAGS)

$(2)/$(1).a: $$(OBJ_ARCHIVE_$(1))
	$$(AR) rcs $$@ $$^

endef

