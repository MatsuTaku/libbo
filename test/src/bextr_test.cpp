//
// Created by 松本拓真 on 2019/11/06.
//

#include "bo/bextr.hpp"
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

TEST(BO_TEST_NAME(Bextr), 64) {
  for (int i = 0; i < N; i++) {
    auto val = rand64();
    int s = random() % 64;
    int l = random() % (64 - s) + 1;
    uint64_t bar = (l < 64) ? (1ull<<l)-1 : -1;
    uint64_t mask = bar << s;

    EXPECT_EQ(bo::bextr_u64(val, s, l), (val & mask) >> s);
  }
}
