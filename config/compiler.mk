ifeq ($(VERSIONNING), true)
	VERSIONNING_CONF = $(shell realpath config/Version.v)
	LDFLAGS += -Wl,--version-script=$(VERSIONNING_CONF) -v
endif
