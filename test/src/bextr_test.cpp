//
// Created by 松本拓真 on 2019/11/06.
//

#include "gtest/gtest.h"

#include "bo/bextr.hpp"

namespace {

constexpr int N = 1<<6;

}

TEST(BextrTest, Basic) {
  for (int i = 0; i < N; i++) {
    int s = rand() % 64;
    int l = rand() % (64 - s) + 1;
    uint64_t bar = (1<<l)-1;
    uint64_t mask = bar << s;

    EXPECT_EQ(bo::bextr_u64(mask, s, l), bar);
  }
}
