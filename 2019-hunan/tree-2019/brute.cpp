#include <bits/stdc++.h>

static const int MOD = 2019;

struct Solver {
  Solver(int n) : tree(n) {
    for (int i = 0, a, b, c; i < n - 1; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      a--;
      b--;
      tree[a].emplace_back(b, c);
      tree[b].emplace_back(a, c);
    }
    for (int u = 0; u < n; ++u) {
      dfs(-1, u, 0);
    }
    result = (result - n) / 2;
  }

  void dfs(int p, int u, int s) {
    result += s == 0;
    for (auto &&e : tree[u]) {
      int v = e.first;
      if (v != p) {
        int ss = s + e.second;
        if (ss >= MOD) {
          ss -= MOD;
        }
        dfs(u, v, ss);
      }
    }
  }

  long long result = 0;
  std::vector<std::vector<std::pair<int, int>>> tree;
};

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    Solver solver{n};
    std::cout << solver.result << std::endl;
  }
}
