#include <bits/stdc++.h>

struct Solver {
  Solver(int n, int m) : n(n), digits(n), range(m) {
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &range[i].first, &range[i].second);
    }
    dfs(0);
  }

  void dfs(int i) {
    if (i < n) {
      for (digits[i] = 0; digits[i] < 10; ++digits[i]) {
        dfs(i + 1);
      }
    } else {
      for (auto &&r : range) {
        int product = 1;
        for (int j = r.first - 1; j < r.second; ++j) {
          product = product * digits[j] % 9;
        }
        if (product) {
          return;
        }
      }
      result++;
    }
  }

  int n, result = 0;
  std::vector<int> digits;
  std::vector<std::pair<int, int>> range;
};

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    printf("%d\n", Solver(n, m).result);
  }
}
