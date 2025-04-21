all: compile_libs

-include $(MK_CONFIG)/template/rules.mk
-include $(MK_CONFIG)/template/sysdeps.mk

# Eval the macro early to define the variable
$(eval $(call GET_SRC_SYSDEPS,sysdeps,SYSDEPS_SRC))

# Debug info (after eval!)
$(info sysdeps src $(SYSDEPS_SRC))

SRC_FOLDER = src csu
SRC := $(shell find $(SRC_FOLDER) -name '*.c')
SRC += $(SYSDEPS_SRC)

$(eval $(call OBJ_RULES,OBJ,$(SRC)))
$(eval $(call COMPILE_LIB,$(NAME),$(LIB_FOLDER),$(OBJ)))
