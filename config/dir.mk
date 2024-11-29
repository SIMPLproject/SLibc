BIN_DIR := bin
OBJ_DIR := obj
SRC_DIR := src
ASM_SRC_DIR := asm_src
INCLUDE_DIR := include

TEST_SRC := benchmark.c

# Create directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)
