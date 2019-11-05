//
// Created by 松本拓真 on 2019/11/06.
//

#include "gtest/gtest.h"

#include "bo/select.hpp"

namespace {

constexpr int N = 1<<6;

}

TEST(ClzTest, Basic) {
  for (int i = 0; i < N; i++) {
    uint64_t x = rand();
    int cnt = 0;
    for (int j = 0; j < 64; j++) {
      if (x & (1<<j)) {
        EXPECT_EQ(bo::select_u64(x, cnt), j);
        cnt++;
      }
    }
  }
}
