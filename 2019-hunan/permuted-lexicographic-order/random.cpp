#include "gen.h"

struct Generator : GeneratorBase {
  Generator(int n, int m, int k) : GeneratorBase(n, m), k(k), lcp(n) {
    for (int i = 1; i < n; ++i) {
      lcp[i] = rnd.next(0, m);
    }
    recur(0, n, 0);
  }

  void recur(int l, int r, int j) {
    if (j < m) {
      std::vector<int> start{l};
      for (int i = l + 1; i < r; ++i) {
        if (lcp[i] == j) {
          start.push_back(i);
        }
      }
      int count = start.size();
      start.push_back(r);
      auto values = random_subset(k, count);
      for (int i = 0; i < count; ++i) {
        for (int p = start[i]; p < start[i + 1]; ++p) {
          out[p][j] = values[i] + 1;
        }
        recur(start[i], start[i + 1], j + 1);
      }
    }
  }

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

  int k;
  std::vector<int> lcp;
};

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  ensure(argc >= 5);
  int T = std::atoi(argv[1]);
  int N = std::atoi(argv[2]);
  int M = std::atoi(argv[3]);
  int k = std::atoi(argv[4]);
  ensure(N <= k);
  bool bad = argc >= 6 && strcmp(argv[5], "bad") == 0;
  while (T--) {
    int n = N < 0 ? rnd.next(1, -N) : N;
    int m = M < 0 ? rnd.next(1, -M) : M;
    Generator g(n, m, k);
    g.shuffle_columns();
    if (bad) {
      g.corrupt();
    }
    g.print();
  }
}
