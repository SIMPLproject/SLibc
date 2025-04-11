
all : $(ARCHIVE_NAME)

CSU = $(BUILD_FOLDER)/csu/csu.a
SYSDEPS = $(BUILD_FOLDER)/sysdeps/sysdeps.a
SRC = $(BUILD_FOLDER)/src/src.a

ALL_FOLDER=$(CSU) $(SYSDEPS) $(SRC)

$(ARCHIVE_NAME) : $(ALL_FOLDER)
	$(CC) -nostdlib -shared -o $@ \
		-Wl,--whole-archive $(ALL_FOLDER) -Wl,--no-whole-archive


$(CSU) :
	make -C csu \
		BUILD_FOLDER=$(BUILD_FOLDER)/csu \
		BUILD_NAME=$(CSU)
		
$(SYSDEPS) :
	make -C sysdeps \
		BUILD_FOLDER=$(BUILD_FOLDER)/sysdeps \
		BUILD_NAME=$(SYSDEPS)

$(SRC) :
	make -C src \
		BUILD_FOLDER=$(BUILD_FOLDER)/src \
		BUILD_NAME=$(SRC)


