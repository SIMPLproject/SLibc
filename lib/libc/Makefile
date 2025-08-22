all: compile_lib_shared compile_lib_archive

-include $(MK_CONFIG)/template/rules.mk
-include $(MK_CONFIG)/template/sysdeps.mk

# Eval the macro early to define the variable
$(eval $(call GET_SRC_SYSDEPS,sysdeps,SYSDEPS_SRC))

# Debug info (after eval!)

SRC_FOLDER = src csu
SRC := $(shell find $(SRC_FOLDER) -name '*.c')
SRC += $(SYSDEPS_SRC)

INCLUDE_FOLDER = -I include
INCLUDE_FOLDER += -I sysdeps/$(SYSTEM)/$(ARCH)

$(eval $(call OBJ_RULES,OBJ,$(SRC)))

$(eval $(call COMPILE_LIB_ARCHIVE,$(NAME),$(LIB_FOLDER),$(OBJ)))
$(eval $(call COMPILE_LIB_SHARED,$(NAME),$(LIB_FOLDER),$(OBJ)))
