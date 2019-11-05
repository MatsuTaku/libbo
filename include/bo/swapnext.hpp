//
// Created by 松本拓真 on 2019/11/06.
//

#ifndef LIBBO_INCLUDE_BO_SWAPNEXT_HPP_
#define LIBBO_INCLUDE_BO_SWAPNEXT_HPP_

#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

namespace bo {

inline constexpr uint64_t swapnext_each1_u64(uint64_t x) {
  return ((x & 0xAAAAAAAAAAAAAAAA) >> 1) | ((x & 0x5555555555555555) << 1);
}

inline constexpr uint64_t swapnext_each2_u64(uint64_t x) {
  return ((x & 0xCCCCCCCCCCCCCCCC) >> 2) | ((x & 0x3333333333333333) << 2);
}

inline constexpr uint64_t swapnext_each4_u64(uint64_t x) {
  return ((x & 0xF0F0F0F0F0F0F0F0) >> 4) | ((x & 0x0F0F0F0F0F0F0F0F) << 4);
}

inline uint64_t swapnext_each8_u64(uint64_t x) {
#ifdef __MMX__

  auto xx = (__m64) x;
  return (uint64_t) _mm_or_si64(_mm_slli_pi16(xx, 8), _mm_srli_pi16(xx, 8));

#else

  return ((x & 0xFF00FF00FF00FF00) >> 8) | ((x & 0x00FF00FF00FF00FF) << 8);

#endif
}

inline uint64_t swapnext_each16_u64(uint64_t x) {
#ifdef __MMX__

  auto xx = (__m64) x;
  return (uint64_t) _mm_or_si64(_mm_slli_pi32(xx, 16), _mm_srli_pi32(xx, 16));

#else

  return ((x & 0xFFFF0000FFFF0000) >> 16) | ((x & 0x0000FFFF0000FFFF) << 16);

#endif
}

inline constexpr uint64_t swapnext_each32_u64(uint64_t x) {
  return (x >> 32) | (x << 32);
}

}

#endif //LIBBO_INCLUDE_BO_SWAPNEXT_HPP_
