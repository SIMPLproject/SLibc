LIB_FOLDER=$(BASE_FOLDER)/lib
export LIB_FOLDER

libs :  libc ld
.PHONY: libs

.PHONY: libc
libc: setup 
	make -C $(LIB_FOLDER)/libc \
		BUILD_FOLDER="$(BUILD_OBJ_FOLDER)/libc" \
		BUILD_LIB_FOLDER="$(BUILD_LIB_FOLDER)" \
		NAME="libc"

.PHONY: ld
ld:  setup   libc
	make -C $(LIB_FOLDER)/ld \
		BUILD_FOLDER="$(BUILD_OBJ_FOLDER)/ld" \
		BUILD_LIB_FOLDER="$(BUILD_LIB_FOLDER)" \
		NAME="ld"

