ifeq ($(TARGET), apple)
	SYSTEM = darwin
else
	SYSTEM = linux
endif

-include config/$(SYSTEM)/*.mk
