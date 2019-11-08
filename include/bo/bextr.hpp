//
// Created by 松本拓真 on 2019/11/05.
//

#ifndef LIBBO_INCLUDE_BO_BEXTR_HPP_
#define LIBBO_INCLUDE_BO_BEXTR_HPP_

#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

#include <cassert>

namespace bo {

/* Bit field extract */
inline uint64_t bextr_u64(uint64_t x, size_t start, size_t len) {
  assert(start + len <= 64);
#ifdef __BMI__

  return _bextr_u64(x, start, len);

#else

  uint64_t mask = len < 64 ? (1ull << len) - 1 : 0xFFFFFFFFFFFFFFFFull;
  return (x >> start) & mask;

#endif
}

} // namespace bo

#endif
