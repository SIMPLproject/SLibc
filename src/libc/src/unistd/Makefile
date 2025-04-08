SRC=$(shell find . -name '*.c')
OBJ = $(SRC:%.c=$(BUILD_FOLDER)/%.o)

all: $(ARCHIVE_NAME)

$(ARCHIVE_NAME) : $(OBJ)
	ar rcs $@ $(OBJ)

$(BUILD_FOLDER)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(BASE_INCLUDE) $(CONFIG_INCLUDE) -o $@ -c $<

clean:
	rm -rf $(BUILD_FOLDER)

.PHONY: all clean
