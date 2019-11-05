//
// Created by 松本拓真 on 2019/11/06.
//

#include "gtest/gtest.h"

#include "bo/clz.hpp"

namespace {

constexpr int N = 1<<6;

}

TEST(ClzTest, Basic) {
  for (int i = 0; i < N; i++) {
    int clz = rand() % 64;
    uint64_t mask = 1ull << (63 - clz);

    EXPECT_EQ(bo::clz_u64(mask), clz);
  }
}
