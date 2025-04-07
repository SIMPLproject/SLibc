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
} SIMPL_0.1;

