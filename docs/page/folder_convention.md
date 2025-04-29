## Folder Convention

### Libraries Structure

- Each library is separated into its own top-level folder based on its name in the `lib/` folder:
  - Examples: `libc/`, `ld/`, `libm/`, etc.
- All libraries share a **global** `include/` directory for external headers.
- Each library also maintains its own **internal** `include/` directory for private headers.

### Special Folders

- `lib/config/` — Contains headers that are only used during build time (e.g., system configuration macros).
- `crt/` — Contains special startup and shutdown files:
  - `_start`, `_init`, `_fini`

### Sysdeps (System Dependencies)

Each library manages its architecture-specific files under `sysdeps/`:

- Path structure: `sysdeps/$(SYSTEM)/$(ARCH)/`
  - Example: `sysdeps/linux/x86_64/`
- Contents:
  - `bits/` folder:
    - Public low-level headers.
    - **Copied** into `build/include/bits/` during the build.
    - Related `.c` files are compiled alongside the main library sources.
  - `__bits/` folder:
    - Internal low-level headers.
    - **Linked** at compile time only (not copied to the public `bits/` folder).
  - All `.c` and `.S` files:
    - Compiled and added to the main `.a` (static archive) and `.so` (shared object) outputs.
