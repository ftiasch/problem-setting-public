#include <bits/stdc++.h>
#include <testlib.h>

// binom{[n]}{k} : O(k \log k)
template <typename Int> std::vector<Int> random_subset(Int n, int k) {
  assert(n >= k);
  std::set<Int> set;
  for (Int i = n - k; i < n; ++i) {
    Int p = rnd.next(static_cast<Int>(0), i);
    if (set.count(p)) {
      set.insert(i);
    } else {
      set.insert(p);
    }
  }
  std::vector<Int> result;
  for (auto elem : set) {
    result.push_back(elem);
  }
  return result;
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int T = std::atoi(argv[1]);
  int n = std::atoi(argv[2]);
  while (T--) {
    if (rnd.next(0, 1)) {
      auto v = random_subset(100, n);
      shuffle(v.begin(), v.end());
      for (auto &&x : v) {
        printf("%d", x);
      }
    } else {
      int len = rnd.next(1, 2 * n);
      for (int i = 0; i < len; ++i) {
        printf("%d", rnd.next(0, 9));
      }
    }
    puts("");
  }
}
