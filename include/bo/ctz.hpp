//
// Created by 松本拓真 on 2019/11/06.
//

#ifndef LIBBO_INCLUDE_BO_CTZ_HPP_
#define LIBBO_INCLUDE_BO_CTZ_HPP_

#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

#include "popcnt.hpp"

namespace bo {

inline uint64_t ctz_u64(uint64_t x) {
#ifdef __BMI__

  return _tzcnt_u64(x);

#else

  return popcnt_u64((x & -x) - 1);

#endif
}

}

#endif //LIBBO_INCLUDE_BO_CTZ_HPP_
