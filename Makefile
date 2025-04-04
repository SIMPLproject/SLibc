-include config/*.mk

LIB_NAME = $(BIN_DIR)/Slibc.a
SO_NAME = $(BIN_DIR)/Slibc.so.1

TEST_BIN := benchmark

ifeq ($(VERBOSE), true)
	CFLAGS += -D VERBOSE
endif

ifeq ($(DEBUG), true)
	CFLAGS += -g
endif

# Source files
SRC = $(shell find $(SRC_DIR) -type f -name '*.c')

# Object files
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Include directories
INCLUDE = -I $(INCLUDE_DIR)
INCLUDE += -I $(SRC_DIR)/config

all: $(OBJ_DIR) $(BIN_DIR) $(LIB_NAME) $(SO_NAME)


# Compile .c files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $< into $@..."
	$(CC) $(CFLAGS) $(PIC_FLAGS) $(INCLUDE) -c $< -o $@
	@test -f $@ || (echo "Error: $@ is not a file! Something went wrong." && exit 1)

# Assemble .s files
$(OBJ_DIR)/%.o: $(ASM_SRC_DIR)/%.s
	@mkdir -p $(dir $@)
	@echo "Assembling $< into $@..."
	$(AS) $(NASM_FLAGS) -o $@ $<
	@test -f $@ || (echo "Error: $@ is not a file! Something went wrong." && exit 1)

# Build static library
$(LIB_NAME): $(OBJ) $(ASM_OBJ)
	@echo "Building static library $(LIB_NAME)..."
	@$(AR) rcs $@ $(filter %.o,$^)

# Build shared library with version script
$(SO_NAME): $(OBJ) $(ASM_OBJ)
	@echo "Building shared library $@..."
	@$(CC) $(LDFLAGS) $(PIC_FLAGS) $(INCLUDE) -shared -o $@ $(OBJ) $(ASM_OBJ)
	@strip --strip-all $@
	ln $(SO_NAME) bin/libc.so
	$(CC) -fno-pie -no-pie -nostdlib -DBUILD_EXECUTABLE config/start.c -c -o bin/crt1.o



# Clean object files
clean:
	@echo "Removing object files..."
	@rm -rf $(OBJ_DIR)

# Full clean of libraries and executables
fclean: clean
	@echo "Removing libraries and executables..."
	@rm -rf $(BIN_DIR)

# Rebuild all
re: fclean all

-include $(OBJ:.o=.d)

.PHONY: all clean fclean re
