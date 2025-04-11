SRC_FOLDER = $(SYSTEM)/$(ARCH)

-include feature.mk
-include $(SRC_FOLDER)/feature.mk
MISSING_FEATURES := $(filter-out $(FEATURE), $(GLOBAL_FEATURE))

$(info $(SRC_FOLDER))

SRC=$(shell find  $(SRC_FOLDER) -name '*.c')
SRC+=$(addprefix misc/, $(addsuffix .c, $(MISSING_FEATURES)))

OBJ = $(SRC:%.c=$(BUILD_FOLDER)/%.o)

all: $(BUILD_NAME)

$(BUILD_NAME) : $(OBJ)
	$(AR) rcs $(AR_FLAG) $@ $(OBJ)

$(BUILD_FOLDER)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(BASE_INCLUDE) $(CONFIG_INCLUDE) -o $@ -c $<

clean:
	rm -rf $(BUILD_FOLDER)

.PHONY: all clean
