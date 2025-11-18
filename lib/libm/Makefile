all: compile

DEPENDENCY_LIB = libc

-include $(MK_CONFIG)/template/rules.mk

SRC_FOLDER = src
SRC := $(shell find $(SRC_FOLDER) -name '*.c')
SRC += $(SYSDEPS_SRC)

$(eval $(call OBJ_RULES,OBJ,$(SRC)))
$(eval $(call COMPILE_LIB_SHARED,$(NAME),$(LIB_FOLDER),$(OBJ)))

compile : $(COMPILE_LIB_SHARED) $(COMPILE_LIB_ARCHIVE)
.PHONY: compile
