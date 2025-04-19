all : compile_libs

-include $(MK_CONFIG)/template/rules.mk

$(info --- $(VERSION_FLAGS))

SRC_FOLDER = src csu
SRC = $(shell find $(SRC_FOLDER) -name '*.c')
$(info SRC -- $(SRC) --)

$(eval $(call OBJ_RULES,OBJ,$(SRC)))

$(eval $(call COMPILE_LIB,$(BUILD_FOLDER)/$(NAME),$(OBJ)))

