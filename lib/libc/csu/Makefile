SRC=$(shell find . -name '*.c')
OBJ = $(SRC:%.c=$(BUILD_FOLDER)/%.o)

all: $(BUILD_NAME)

$(BUILD_NAME) : $(OBJ)
	$(AR) rcs $(AR_FLAG) $@ $(OBJ)

$(BUILD_FOLDER)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(BASE_INCLUDE) $(CONFIG_INCLUDE) -o $@ -c $<

clean:
	rm -rf $(BUILD_FOLDER)

.PHONY: all clean
