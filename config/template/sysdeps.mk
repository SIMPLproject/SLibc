# $(1) sysdeps path
# $(2) SRC_DEST
define GET_SRC_SYSDEPS
  $(eval __SYSDEPS_SRC_PATH := $(1)/$(SYSTEM)/$(ARCH))
  $(eval $(2) := $(shell find $(__SYSDEPS_SRC_PATH)  \( -name "*.c" -o -name "*.S" \)))
endef
