//
// Created by 松本拓真 on 2019/11/06.
//

#include "gtest/gtest.h"

#include "bo/bextr.hpp"
#include <random>

namespace {

constexpr int N = 1<<16;

std::default_random_engine eng(12345);
std::uniform_int_distribution<uint64_t> dist;
uint64_t rand64() {
  return dist(eng);
}

}

TEST(Bextr, 64) {
  for (int i = 0; i < N; i++) {
    auto val = rand64();
    int s = random() % 64;
    int l = random() % (64 - s) + 1;
    uint64_t bar = (l < 64) ? (1ull<<l)-1 : -1;
    uint64_t mask = bar << s;

    EXPECT_EQ(bo::bextr_u64(val, s, l), (val & mask) >> s);
  }
}
