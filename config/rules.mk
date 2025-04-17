

ifdef NATIVE


ifeq ($(NATIVE), default)

$(OBJ_DIR)/%_template.o: %_template.c
	#do nothing

$(OBJ_DIR)/%.o : %.c
	$(CC) $(CFLAGS) $(DISABLE_VECTORISE) -c $< -o $@ 


else

$(OBJ_DIR)/%_default.o: %_default.c
	#do nothing

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -DNATIVE=$(NATIVE) -m$(NATIVE)

endif

else

define TEMPLATE_RULES
$(OBJ_DIR)/$1/$1_template_$2.o: $1/$1_template.c
	@mkdir -p $$(dir $$@)
	$$(CC) $$(CFLAGS) -c $$< -o $$@ -m$2
endef

$(foreach name,$(SRC_NAMES),\
	$(foreach ver,$(VERSION_FLAGS),\
		$(eval $(call TEMPLATE_RULES,$(name),$(ver)))\
	)\
)

$(OBJ_DIR)/%_config_shared.o: %_config.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -DSHARED

$(OBJ_DIR)/%_config_archive.o: %_config.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -DARCHIVE

endif
