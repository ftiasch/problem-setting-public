#include <bits/stdc++.h>
#include <testlib.h>

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
  int PM = std::atoi(argv[1]);
  int T = std::atoi(argv[2]);
  int N = std::atoi(argv[3]);
  while (T--) {
    int nm = N < 0 ? rnd.next(2, -N) : N;
    int n = rnd.next(1, nm - 1);
    int m = nm - n;
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++i) {
      auto sep = random_subset(PM - 1, n + m - 1);
      sep.push_back(-1);
      sep.push_back(PM - 1);
      std::sort(sep.begin(), sep.end());
      for (int j = 1; j <= n + m; ++j) {
        printf("%d%c", sep[j] - sep[j - 1], " \n"[j == n + m]);
      }
    }
  }
}
