/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
 */

#ifndef BO_BEXTR_HPP_
#define BO_BEXTR_HPP_

#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif
#include <cstdint>
#include <cassert>

namespace bo {

constexpr uint32_t bextr_u32_constexpr(uint32_t x, unsigned start, unsigned len) {
  assert(start + len <= 32);
  uint32_t mask = len < 32 ? (1ull << len) - 1 : 0xFFFFFFFFu;
  return (x >> start) & mask;
}

/** Bit field extract */
inline uint32_t bextr_u32(uint32_t x, unsigned start, unsigned len) {
#ifdef __BMI__
  return _bextr_u32(x, start, len);
#else
  return bextr_u32_constexpr(x, start, len);
#endif
}

constexpr uint64_t bextr_u64_constexpr(uint64_t x, unsigned start, unsigned len) {
  assert(start + len <= 64);
  uint64_t mask = len < 64 ? (1ull << len) - 1 : 0xFFFFFFFFFFFFFFFFull;
  return (x >> start) & mask;
}

/** Bit field extract */
inline uint64_t bextr_u64(uint64_t x, unsigned start, unsigned len) {
#ifdef __BMI__
  return _bextr_u64(x, start, len);
#else
  return bextr_u64_constexpr(x, start, len);
#endif
}

} // namespace bo

#endif /* BO_BEXTR_HPP_ */
