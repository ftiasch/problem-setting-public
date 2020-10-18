#include "testlib.h"

#include <array>
#include <cstdlib>
#include <set>

template <int k> std::array<int, k> rand_subset(int n) {
  std::set<int> set;
  for (int i = n - k; i < n; ++i) {
    int p = rnd.next(static_cast<int>(0), i);
    if (set.count(p)) {
      set.insert(i);
    } else {
      set.insert(p);
    }
  }
  std::array<int, k> result;
  int index = 0;
  for (auto x : set) {
    result[index++] = x;
  }
  return result;
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int T = std::atoi(argv[1]);
  const int m = std::atoi(argv[2]);

  while (T--) {
    auto y = rand_subset<3>(m);
    for (int i = 0; i < 3; ++i) {
      auto x = rand_subset<2>(m);
      printf("%d %d %d\n", x[0], x[1], y[i]);
    }
  }
}
