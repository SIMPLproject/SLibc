# Folder convention

lib/config  is for include that will only be use during build time
crt is for the _start file _init and _fini

each lib has is sysdeps where the header will be copy into include/bits in the build folder and the c file compile with the rest
