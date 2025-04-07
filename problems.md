# Compile without the entire glibc pipeline

```
working : 
clang -nostartfiles bin/crt1.o -Lbin -lc -Iinclude test/test.c -o a.out -Wl,-rpath=$PWD/bin -g
```

```
clang -nostdlib -nostartfiles bin/crt1.o -Lbin -Wl,-Bstatic -lc -Iinclude test/test.c -o a.out
```

error 
```

/usr/bin/ld: /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/libc.a(iofclose.o): in function `_IO_new_fclose.cold':
(.text.unlikely+0x33): undefined reference to `_Unwind_Resume'
/usr/bin/ld: /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/libc.a(iofclose.o):(.data.rel.local.DW.ref.__gcc_personality_v0[DW.ref.__gcc_personality_v0]+0x0): undefined reference to `__gcc_personality_v0'
/usr/bin/ld: /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/libc.a(iofflush.o): in function `_IO_fflush.cold':
(.text.unlikely+0x32): undefined reference to `_Unwind_Resume'
/usr/bin/ld: /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/libc.a(iofputs.o): in function `_IO_fputs.cold':
(.text.unlikely+0x32): undefined reference to `_Unwind_Resume'
/usr/bin/ld: /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/libc.a(iofwrite.o): in function `_IO_fwrite.cold':
(.text.unlikely+0x32): undefined reference to `_Unwind_Resume'
/usr/bin/ld: /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/libc.a(wfileops.o): in function `_IO_wfile_underflow.cold':
(.text.unlikely+0x33): undefined reference to `_Unwind_Resume'
/usr/bin/ld: /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/libc.a(fileops.o): in function `_IO_new_file_underflow.cold':
(.text.unlikely+0x35): undefined reference to `_Unwind_Resume'
/usr/bin/ld: /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/libc.a(printf_fp.o): in function `__printf_fp_l':
(.text+0x537): undefined reference to `__unordtf2'
/usr/bin/ld: (.text+0x57c): undefined reference to `__unordtf2'
/usr/bin/ld: (.text+0x5a2): undefined reference to `__letf2'
/usr/bin/ld: /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/libc.a(printf_fphex.o): in function `__printf_fphex':
(.text+0xa2): undefined reference to `__unordtf2'
/usr/bin/ld: (.text+0xcb): undefined reference to `__unordtf2'
/usr/bin/ld: (.text+0xe3): undefined reference to `__letf2'
/usr/bin/ld: /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/libc.a(iogetdelim.o): in function `__getdelim.cold':
(.text.unlikely+0x32): undefined reference to `_Unwind_Resume'
/usr/bin/ld: /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/libc.a(pthread_once.o): in function `__pthread_once_slow.cold':
(.text.unlikely+0x25): undefined reference to `_Unwind_Resume'
/usr/bin/ld: /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/libc.a(libc-start.o): in function `__libc_start_main_impl':
(.text+0x1c77): undefined reference to `_init'
/usr/bin/ld: /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/libc.a(libc-start.o): in function `call_fini':
(.text+0x3b9): undefined reference to `_fini'
/usr/bin/ld: /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/libc.a(dl-reloc-static-pie.o): in function `_dl_relocate_static_pie':
(.text+0x31): undefined reference to `_DYNAMIC'
/usr/bin/ld: (.text+0x91): undefined reference to `_DYNAMIC'
/usr/bin/ld: (.text+0x9c): undefined reference to `_DYNAMIC'
/usr/bin/ld: /tmp/test-20a3a5.o: in function `main':
test.c:(.text+0x2b): undefined reference to `printf'
/usr/bin/ld: a.out: hidden symbol `_DYNAMIC' isn't defined
/usr/bin/ld: final link failed: bad value
clang: error: linker command failed with exit code 1 (use -v to see invocation)

```


