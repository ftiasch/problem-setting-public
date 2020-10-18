#include "testlib.h"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <vector>

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  int min_n = std::atoi(argv[1]);
  int max_n = std::atoi(argv[2]);
  int N = std::atoi(argv[3]);
  std::vector<int> ns;
  while (N >= min_n) {
    ns.emplace_back(rnd.next(min_n, std::min(N, max_n)));
    N -= ns.back();
  }
  for (auto n : ns) {
    for (int i = 0; i < n; ++i) {
      putchar("01?"[rnd.next(3)]);
    }
    puts("");
  }
  return 0;
}
