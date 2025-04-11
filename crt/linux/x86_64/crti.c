__asm__(
    ".section .init\n"
    "call __init_array_start\n"
    ".section .fini\n"
    "call __fini_array_start\n"
);
