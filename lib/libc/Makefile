all : compile_libs

-include $(MK_CONFIG)/template/rules.mk

$(info --- $(VERSION_FLAGS))
$(info name $(NAME))

SRC_FOLDER = src csu
SRC = $(shell find $(SRC_FOLDER) -name '*.c')
$(info SRC -- $(SRC) --)

$(eval $(call OBJ_RULES,OBJ,$(SRC)))

$(info $(call COMPILE_LIB,$(NAME),$(LIB_FOLDER),$(OBJ)))
$(eval $(call COMPILE_LIB,$(NAME),$(LIB_FOLDER),$(OBJ)))

