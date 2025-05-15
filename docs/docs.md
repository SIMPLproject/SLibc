# SIMPL Libc Documentation

Welcome to the SIMPL Libc documentation. This guide explains the overall library architecture, conventions, and rules that ensure a clean, scalable implementation.

Each section of this documentation explains one major principle or rule you must follow when contributing to or understanding SIMPL Libc.

## Library Architecture Overview

- Each library (`libc`, `libm`, `ld`, etc.) is isolated in its own folder.
- System and architecture-specific code is isolated into `sysdeps` directories.
- Name of file impact how it is compile.
- Vectorized and optimized versions of functions are managed cleanly through naming conventions and IFUNC dispatch mechanisms.
- Startup and shutdown code (`crt/`) are built separately and handled cleanly.

You can find detailed explanations about each part of the system in the sections below:

## Documentation Index

- [Folder Convention](page/folder_convention.md)
- [Compilation Rules](page/compilation.md)
- [File Naming Convention](page/file_naming_convention.md)
- [Symbol Visibility and Declaration](page/symbol.md)

---
