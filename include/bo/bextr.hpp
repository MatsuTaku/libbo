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
inline uint64_t bextr_u64(const uint64_t x, const size_t start, const size_t len) {
  assert(start + len <= 64);
#ifdef __BMI__

  return _bextr_u64(x, start, len);

#else

  return (x >> start) & ((1ull << len) - 1);

#endif
}

} // namespace bo

#endif
