#include <testlib.h>
#include <bits/stdc++.h>

struct GeneratorBase {
  GeneratorBase(int n, int m) : n(n), m(m), out(n, std::vector<int>(m)) {}

  void shuffle_columns() {
    auto copy = out;
    std::vector<int> order(m);
    std::iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end());
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        out[i][j] = copy[i][order[j]];
      }
    }
  }

  void corrupt() {
    auto copy = out;
    std::vector<int> order(n);
    std::iota(order.begin(), order.end(), 0);
    if (n > 1) {
      bool ok = false;
      do {
        shuffle(order.begin(), order.end());
        ok = false;
        for (int i = 0; i < n; ++i) {
          ok |= order[i] != i;
        }
      } while (!ok);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        out[i][j] = copy[order[i]][j];
      }
    }
  }

  void print() {
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        printf("%d%c", out[i][j], " \n"[j == m - 1]);
      }
    }
  }

  int n, m;
  std::vector<std::vector<int>> out;
};
