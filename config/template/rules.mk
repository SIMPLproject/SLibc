-include $(MK_CONFIG)/lib.mk
-include sysdeps.mk

ifdef NATIVE

# $(1) obj_name
# $(2) src
define OBJ_RULES
__SRC_$(1)_BASE := $$(filter-out %.S %_generic.c %_simd.c,$(2))
__SRC_$(1)_ASM := $$(filter %.S,$(2))

$(1) = $$(patsubst %.c,$$(BUILD_FOLDER)/%.o,$$(__SRC_$(1)_BASE))
$(1) += $$(patsubst %.S,$$(BUILD_FOLDER)/%.o,$$(__SRC_$(1)_ASM))
endef


else  # no NATIVE defined

# $(1) obj_name
# $(2) src
define OBJ_RULES
__SRC_$(1)_BASE := $$(filter-out %.S %_build.c %_simd.c,$(2))
__SRC_$(1)_CONFIG := $$(filter %_build.c,$(2))
__SRC_$(1)_TEMPLATE := $$(filter %_simd.c,$(2))
__SRC_$(1)_ASM := $$(filter %.S,$(2))

$(1) = $$(patsubst %.c,$$(BUILD_FOLDER)/%.o,$$(__SRC_$(1)_BASE))
$(1) += $$(foreach flag,$$(VERSION_FLAGS),$$(patsubst %_simd.c,$$(BUILD_FOLDER)/%_$$(flag)_shared.o,$$(__SRC_$(1)_TEMPLATE)))
$(1) += $$(patsubst %.c,$$(BUILD_FOLDER)/%_archive.o,$$(__SRC_$(1)_CONFIG))
$(1) += $$(patsubst %.c,$$(BUILD_FOLDER)/%_shared.o,$$(__SRC_$(1)_CONFIG))
$(1) += $$(patsubst %.S,$$(BUILD_FOLDER)/%.o,$$(__SRC_$(1)_ASM))
endef

endif

INCLUDE = $(BASE_INCLUDE) $(CONFIG_INCLUDE)

define TEMPLATE_RULES
$(BUILD_FOLDER)/%_$(1)_shared.o : %_simd.c
	mkdir -p $$(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -m$(1) -c $$< -o $$@
endef


$(foreach flag,$(VERSION_FLAGS),\
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

$(BUILD_FOLDER)/%.o: %.S
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


ifdef DEPENDENCY_LIB
__DEPENDENCY_LIB  = $(foreach lib,$(DEPENDENCY_LIB), $(BUILD_LIB_FOLDER)/$($(lib)_NAME).a )

# base include internal
INCLUDE  += $(foreach lib,$(DEPENDENCY_LIB), -I $(LIB_FOLDER)/$(lib)/include )
# sysdeps include
INCLUDE  += $(foreach lib,$(DEPENDENCY_LIB), -I $(LIB_FOLDER)/$(lib)/$(SYSDEPS_SRC_PATH))
endif


# $(1) lib name
# $(2) lib build folder
# $(3) OBJ
define COMPILE_LIB_SHARED
COMPILE_LIB_SHARED := $(2)/$(1).so 

$$(eval OBJ_SHARED_$(1) := $$(filter-out %_archive.o,$(3)))

$(2)/$(1).so: $$(OBJ_SHARED_$(1))
	$$(CC) -shared -Wl,-soname,$(1).so -nostdlib  -ffunction-sections -fdata-sections -o $$@  $$^ -Wl,--gc-sections -Wl,--as-needed $(__DEPENDENCY_LIB)
	# strip --strip-unneeded $$@
endef

# $(1) lib name
# $(2) lib build folder
# $(3) OBJ
define COMPILE_LIB_ARCHIVE
COMPILE_LIB_ARCHIVE := $(2)/$(1).a
$$(eval OBJ_ARCHIVE_$(1) := $$(filter-out %_shared.o %_generic.o,$(3)))

$(2)/$(1).a: $$(OBJ_ARCHIVE_$(1))
	$$(AR) rcs $$@  $$^

endef

-include $(BUILD_FOLDER)/**/*.d
-include $(BUILD_FOLDER)/*.d
