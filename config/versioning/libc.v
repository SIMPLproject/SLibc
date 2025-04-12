SIMPL_0.1 {
	global:
		strlen;
		strcmp;
		strncmp;
		exit;

		memset;
		memcpy;
		memmove;
		strchr;
		strncpy;

		malloc;
		free;
	local:
		*;
};

SIMPL_0.2 {
	global:
		printf;
		__printf_chk;
} SIMPL_0.1;

