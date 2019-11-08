//
// Created by 松本拓真 on 2019/11/05.
//

#ifndef LIBBO_INCLUDE_CLZ_HPP_
#define LIBBO_INCLUDE_CLZ_HPP_

#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

#include <cassert>
#include "bextr.hpp"

namespace bo {

// floor(log_2(x)) + 1
inline constexpr uint8_t log2p1_u8(uint8_t x) {
  if (x >= 0x80)
    return 8;

  uint64_t p = uint64_t(x) * 0x0101010101010101ull;
  p -= 0x8040201008040201ull;
  p = ~p & 0x8080808080808080ull;
  p >>= 7;
  p *= 0x0101010101010101ull;
  p >>= 56;
  return p & 0b1111;
}

// Most Significant-Set Bit
inline constexpr uint8_t mssb_u8(uint8_t x) {
  assert(x != 0);
  return log2p1_u8(x) - 1;
}

// summarize x_{1-8} by follows:
// { 0: x = 0
//   1: 1 <= x < 256
inline uint8_t summary_u64_each8(uint64_t x) {
#ifdef __MMX__

  auto c = uint64_t(_mm_cmpeq_pi8(__m64(x), __m64(0ull)));
  c = ~c & 0x8080808080808080ull;

#else

  constexpr uint64_t hmask = 0x8080808080808080ull;
  constexpr uint64_t lmask = 0x7F7F7F7F7F7F7F7Full;
  uint64_t a = x & hmask;
  uint64_t b = x & lmask;
  b = hmask - b;
  b = ~b;
  auto c = (a | b) & hmask;

#endif
  c *= 0x0002040810204081ull;
  return c >> 56;
}

inline uint64_t clz_u64(uint64_t x) {
#ifdef __LZCNT__

  return _lzcnt_u64(x);

#else

  if (x == 0)
    return 64;
  auto i = mssb_u8(summary_u64_each8(x));
  auto j = mssb_u8(uint8_t(bextr_u64(x, i * 8, 8)));
  return 63 - (i * 8 + j);

#endif
}

} // namespace bo

#endif //LIBBO_INCLUDE_CLZ_HPP_
