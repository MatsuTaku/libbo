# libbo

C++ Header-only Library of Practical Intrinsics.

[![build](https://github.com/MatsuTaku/libbo/actions/workflows/cmake_test.yml/badge.svg)](https://github.com/MatsuTaku/libbo/actions/workflows/cmake_test.yml)

This library is created based on the following design principles:
- Provides intrinsic interfaces convenience for basic **bit-manipulations** and **implementing succinct data structures**.
- Optimized intrinsic implementations can be used for any platform without considering the supporting architecture by the CPU.
- Provides compile-time constant (a.k.a. constexpr) impelementaions for most interfaces.

## Supporting bit operations

  - ctz - count trailing zeros
    - `ctz(0b00110110) -> 1`
  - clz - count leading zeros
    - `clz(0b00110110) -> 2`
  - popcnt - poplation count
    - `popcnt(0b00110110) -> 4`
  - bextr - bits extract
    - `bextr(0b00110110, 2, 4) -> 0b00001101`
  - select - index of nth 1 (0-indexed)
    - `select(0b00110110, 2) -> 4`
  - bitreverse - bitwise reverse
    - `bextr(0b00110110) -> 0b01101100`
  - swapnext - swap next nth bits to each other
    - `swapnext2(0b 00 11 01 10) -> 0b 11 00 10 01`
  
  ## LICENSE
  This library is licensed by The Unlicense.
  
  ## Usage
  You can handle libbo only including header directory at `/include`.</br>
  If you using CMake to your project, you just add `add_subdirectory(path/to/libbo)`.
  
  You can compile best binary for platforms by just adding compile option only `-march=native` (or `-mcpu=native` in LLVM based comilers).
  
