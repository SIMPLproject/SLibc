
__attribute__((noreturn)) void exit(int status)
{
	(void)status;
	while(1) {}
}
