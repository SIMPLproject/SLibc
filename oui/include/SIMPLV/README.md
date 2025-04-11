# SIMPLV – A Seamless SIMD Vector Library

```SIMPLV``` is a SIMD (Single Instruction, Multiple Data) vector library, part of the ```SIMPL_libc```, that simplifies the complexities of cross-architecture SIMD programming. With SIMPLV, you can write highly optimized vectorized code that works effortlessly across multiple CPU architectures, including ARM, x86, and x86-64.

## Key Features
**Architecture-Aware Optimization:** Automatically adapts to the hardware, allowing transitions between SIMD instruction sets such as AVX, SSE, and NEON with no extra effort.

**Register Scaling:** Automatically scales 128-bit registers to 256-bit where possible, ensuring maximum utilization of your hardware's potential.

**Unified API:** A simple and intuitive API that abstracts away the low-level differences between SIMD architectures, letting you focus on coding, not hardware.


## Installation
To include SIMPLV in your project, simply clone the repository and add it to your build system:

``` bash
git clone https://github.com/bonsthie/simplv.git
```

Ensure that the necessary flags for your compiler are enabled to support AVX, SSE, or NEON, depending on the target architecture.

# Usage
The library provides a straightforward API for SIMD operations. Here's an example of how you can add two vectors of integers using SIMPLV:

```c
#include <simplv.h>

{
  vec v1 = v256b_load_char('a');
  vec v2 = v256b_load_char('b');

  vec result = v32c_add(v1, v2);
}
```

Where `vec` is a vector type, `v256b_load_char()` loads characters into 256-bit registers, and `v32c_add()` performs vector addition for character types. **SIMPLV** automatically optimizes the operation based on the underlying hardware.

Supported Architectures
**ARM** (NEON instructions)
**x86/x86-64** (SSE, AVX)

## Contributing
Contributions are welcome! Feel free to open issues or submit pull requests to help improve the project. All contributions should align with the goal of making SIMD programming easier and more accessible.

## License
**SIMPLV** is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.

@at0m741 and @Bonsthie
