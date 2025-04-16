## Compilation of the Lib - Explained

### Introduction
I know that the Makefile for the library could be a simple 100-line file, like in musl, but I chose to have one `Makefile` per folder. This gives more flexibility for how to compile each part. For example, in the string library, the template file is compiled multiple times based on the architecture (SSE, AVX, etc.). You can read more about this specific case in the [libc string folder](../lib/libc/src/string/Makefile).

### Configuration Folder
In the [config folder](../config), you'll find the default Makefile settings based on the architecture and OS. In the future, a `./configure` script will be available to modify libc settings, enable debug mode, etc.

### Makefile Workflow

#### Presentation
The main Makefile is divided into five parts:

1. Compile CRT files (`crt1.o`, etc.) used for program startup, initialization, and finalization.
2. Copy the `include/` folder into the build folder, and resolve the appropriate `bits/` folder based on the architecture.
3. Compile each static library archive found in the [lib folder](../lib).
4. Create the shared library according to the settings defined in the [lib config file](../config/lib.mk).
5. Provide utility targets like `clean`, `fclean`, and create a small Clang wrapper.

#### How Args Are Passed

Base flags like `CFLAGS`, `CC`, `BASE_INCLUDE`, etc., are exported from the main Makefile:

```makefile
export CC
export AR
export AR_FLAGS
export CFLAGS
export DISABLE_VECTORISE
```

Each subdirectory Makefile is invoked with its own arguments for the build folder and archive name:

```makefile
$(MAKE) -C lib/foo \
	BUILD_FOLDER="$(BUILD_OBJ_FOLDER)/foo" \
	ARCHIVE_NAME="$(BUILD_LIB_FOLDER)/foo.a"
```

#### Rules

Each folder has its own rules. As mentioned earlier, the string folder is a good example: if the Makefile needs to compile with SIMD optimizations on x86_64, it generates multiple versions depending on the supported architectures via the `VERSION_FLAGS = sse avx` variable. Each version is compiled, and an IFUNC is used to resolve the correct symbol at runtime.

