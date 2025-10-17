int errno = 0;

int *__get_errno_location(void) {
    return &errno;
}
