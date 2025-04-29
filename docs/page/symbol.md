## Symbol Visibility and Declaration

In SIMPL Libc, **only public-facing functions** should be visible to the user. **Internal functions** must remain hidden to avoid polluting the symbol table and to improve internal performance.

### Visibility Rules

- **Internal-only functions** must be either:
  - Marked `static`, or
  - Declared using `__hidden` from `<sys/ctypes.h>`.
- **Public functions** (such as `strlen`, `memcpy`, etc.) must:
  - Expose a **hidden internal symbol** (to allow internal libc calls without passing through the PLT).
  - Provide a **weak alias** for external users, so they can override the symbol if needed.

> **Note:**  
> `malloc` and `free` are special cases.  
> They **must** always use the PLT for calls (even internally), to allow runtime overloading (e.g., custom allocators).

### Declaration Structure

Each public function should follow this structure:

#### Source File (`foo.c`)
```c
// Internal implementation with hidden name
int __foo(void)
{
    return 2;
}

// Expose foo() as a weak alias of __foo
simpl_weak_alias(foo, __foo)
// Make __foo hidden internally
libc_hidden_alias(foo, __foo)
```

#### Header File (`foo.h`)
```c
// External declaration
int foo(void);

// Mark the symbol as hidden internally
libc_hidden_proto(foo);
```

This ensures:
- External users call `foo()`.
- Internal libc code directly calls the hidden `__foo()`, bypassing the PLT for efficiency.
- Users can override `foo()` without breaking internal libc behavior.
