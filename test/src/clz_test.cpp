//
// Created by 松本拓真 on 2019/11/06.
//

#include "gtest/gtest.h"

#include "bo/clz.hpp"
#include <random>

namespace {

constexpr int N = 1<<16;

std::default_random_engine eng(12345);
std::uniform_int_distribution<uint64_t> dist;
uint64_t rand64() {
  return dist(eng);
}

}

TEST(Clz, 64) {
  for (int i = 0; i < N; i++) {
    auto val = rand64();
    int clz = 64;
    for (int j = 63; j >= 0; j--) {
      if (val & (1ull << j)) {
        clz = 63 - j;
        break;
      }
    }

    EXPECT_EQ(bo::clz_u64(val), clz);
  }
}
