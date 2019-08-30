#include <bits/stdc++.h>

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    std::vector<std::vector<int>> lsts(n);
    for (int i = 0; i < n; ++i) {
      lsts[i].push_back(i);
    }
    while (m--) {
      int a, b;
      scanf("%d%d", &a, &b);
      a--;
      b--;
      for (auto &&x : lsts[b]) {
        lsts[a].push_back(x);
      }
      lsts[b].clear();
      std::reverse(lsts[a].begin(), lsts[a].end());
    }
    printf("%d", static_cast<int>(lsts[0].size()));
    for (auto &&x : lsts[0]) {
      printf(" %d", x + 1);
    }
    puts("");
  }
}
