#include <bits/stdc++.h>

static const int MOD = 2019;

struct Solver {
  Solver(int n) : n(n), tree(n), down(n), up(n) {
    for (int i = 0, a, b, c; i < n - 1; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      a--;
      b--;
      tree[a].emplace_back(b, c);
      tree[b].emplace_back(a, c);
    }
    dfs1(-1, 0);
    up[0] = down[0];
    dfs2(-1, 0);
    result = (result - n) / 2;
  }

  void dfs1(int p, int u) {
    down[u][0] = 1;
    for (auto &&e : tree[u]) {
      int v = e.first;
      if (v != p) {
        dfs1(u, v);
        for (int r = 0; r < MOD; ++r) {
          down[u][(r + e.second) % MOD] += down[v][r];
        }
      }
    }
  }

  void dfs2(int p, int u) {
    result += up[u][0];
    for (auto &&e : tree[u]) {
      int v = e.first;
      int w = e.second;
      if (v != p) {
        up[v] = down[v];
        for (int r = 0; r < MOD; ++r) {
          up[v][(r + w) % MOD] += up[u][r];
          up[v][(r + w + w) % MOD] -= down[v][r];
        }
        dfs2(u, v);
      }
    }
  }

  int n;
  long long result = 0;
  std::vector<std::vector<std::pair<int, int>>> tree;
  std::vector<std::array<int, MOD>> down, up;
};

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    Solver solver{n};
    std::cout << solver.result << std::endl;
  }
}
