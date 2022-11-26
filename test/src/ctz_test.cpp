//
// Created by 松本拓真 on 2019/11/09.
//

#include "gtest/gtest.h"

#include "bo/ctz.hpp"
#include <random>

namespace {

constexpr int N = 1<<16;

std::default_random_engine eng(12345);
std::uniform_int_distribution<uint64_t> dist;
uint64_t rand64() {
  return dist(eng);
}

}

TEST(Ctz, 64) {
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
