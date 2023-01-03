//
// Created by 松本拓真 on 2019/11/09.
//

#include "bo/ctz.hpp"
#include "gtest/gtest.h"
#include <random>

#ifdef BO_INTRINSIC_ENABLED
#define BO_TEST_NAME(x) x##_Intrin
#else
#define BO_TEST_NAME(x) x
#endif

namespace {

constexpr int N = 1<<20;

std::default_random_engine eng(12345);
std::uniform_int_distribution<uint64_t> dist;
uint64_t rand64() {
  return dist(eng);
}

}

TEST(BO_TEST_NAME(Ctz), 64) {
  for (int i = 0; i < N; i++) {
    auto val = rand64();
    int ctz = 64;
    for (int j = 0; j < 64; j++) {
      if (val & (1ull << j)) {
        ctz = j;
        break;
      }
    }

    EXPECT_EQ(bo::ctz_u64(val), ctz);
  }
}
