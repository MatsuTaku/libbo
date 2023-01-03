#include "bo/prefetch.hpp"
#include <array>

int main() {
  std::array<int,16> arr;
  bo::prefetch_l1((const char*)arr.data());
}