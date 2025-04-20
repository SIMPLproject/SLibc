## File Naming Convention in SIMPL Libc

In SIMPL Libc, each function that supports architecture-specific vectorization follows a consistent and scalable file naming pattern. This structure ensures clarity, maintainability, and compatibility with multi-architecture builds using SIMD and IFUNC.

### File Types

Each function may have up to **three source files**:

| File Suffix     | Purpose                                                                 |
|------------------|-------------------------------------------------------------------------|
| `_generic.c`     | Contains the scalar fallback implementation. Always compiled without simd.          |
| `_simd.c`        | Contains the SIMD/vectorized implementation. Compiled once per SIMD flag (e.g., `-mavx2`, `-msse2`, `-mneon`). |
| `_build.c`       | Contains the IFUNC resolver or dispatch logic, with weak aliasing and architecture selection. |

### Rules

- All functions must be named using the `ARCH_SYM(func)` macro (or be `static`) to ensure proper symbol resolution.
- If you want to provide vectorization support for a function, you must:
  1. Implement the scalar version in a `_generic.c` file.
  2. Implement the SIMD versions in a `_simd.c` file.
  3. Provide a `_build.c` file that sets up the IFUNC or weak dispatching logic.
- Functions without a `_simd.c` file will only be compiled as scalar.
- Functions without a `_build.c` file will be treated as a single implementation (no dispatch).

### Compilation Behavior

- `_generic.c` is always compiled and used as a baseline.
- `_simd.c` is compiled multiple times with different SIMD flags as specified by the `VECTOR` list (e.g., AVX, SSE, NEON).
- `_build.c` creates the resolver used by IFUNC to pick the optimal implementation at runtime.

### Example: `memcpy`

```
memcpy_generic.c   // baseline scalar implementation
memcpy_simd.c      // SIMD variants compiled with vector flags
memcpy_build.c     // IFUNC/dispatch setup to choose the best version
```

This structure keeps SIMPL clean, predictable, and easy to extend with additional architectures or optimization strategies.

