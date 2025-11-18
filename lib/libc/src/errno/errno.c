long errno = 0;

long *__get_errno_location(void) {
    return &errno;
}
