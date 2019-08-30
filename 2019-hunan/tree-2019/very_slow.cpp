#include <bits/stdc++.h>

static const int MOD = 2019;

struct Solver {
  Solver(int n)
      : head(n, -1), to(n - 1 << 1), next(n - 1 << 1), weight(n - 1),
        valid(n - 1 << 1), dp(n - 1 << 1) {
    for (int i = 0, a, b, c; i < n - 1; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      a--;
      b--;
      add_edge(i << 1, a, b);
      add_edge(i << 1 | 1, b, a);
      weight[i] = c;
    }
    for (int i = 0; i < n - 1 << 1; ++i) {
      dfs(i);
      result += dp[i][0];
    }
    result /= 2;
  }

  void add_edge(int i, int a, int b) {
    to[i] = b;
    next[i] = head[a];
    head[a] = i;
  }

  void dfs(int i) {
    if (!valid[i]) {
      valid[i] = true;
      int p = to[i ^ 1];
      int u = to[i];
      int w = weight[i >> 1];
      dp[i][w] = 1;
      for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
        int v = to[iterator];
        if (v != p) {
          dfs(iterator);
          for (int r = 0; r + w < MOD; ++r) {
            dp[i][r + w] += dp[iterator][r];
          }
          for (int r = MOD - w; r < MOD; ++r) {
            dp[i][r + w - MOD] += dp[iterator][r];
          }
        }
      }
    }
  }

  long long result = 0;
  std::vector<int> head, to, next, weight;
  std::vector<bool> valid;
  std::vector<std::array<int, MOD>> dp;
};

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    Solver solver{n};
    std::cout << solver.result << std::endl;
  }
}
