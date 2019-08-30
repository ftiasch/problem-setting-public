#include <bits/stdc++.h>

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    std::vector<int> link(n);
    std::vector<std::pair<int, int>> ends(n);
    for (int i = 0; i < n; ++i) {
      ends[i] = {i, i};
    }
    auto unlink = [&](int u) {
      if (ends[u].first != ends[u].second) {
        link[ends[u].first] ^= ends[u].second;
        link[ends[u].second] ^= ends[u].first;
      }
    };
    auto mklink = [&](int u, int v) {
      link[u] ^= v;
      link[v] ^= u;
    };
    auto empty = std::make_pair(-1, -1);
    while (m--) {
      int a, b;
      scanf("%d%d", &a, &b);
      a--;
      b--;
      if (ends[a] == empty) {
        ends[a] = ends[b];
        ends[b] = empty;
      } else if (ends[b] != empty) {
        unlink(a);
        unlink(b);
        mklink(ends[a].second, ends[b].first);
        mklink(ends[b].second, ends[a].first);
        ends[a].second = ends[b].second;
      }
      ends[b] = empty;
      std::swap(ends[a].first, ends[a].second);
    }
    std::vector<int> result;
    if (ends[0] != empty) {
      int p = ends[0].first;
      int q = ends[0].second;
      do {
        result.push_back(p);
        q ^= link[p];
        std::swap(p, q);
      } while (q != ends[0].second);
    }
    printf("%d", static_cast<int>(result.size()));
    for (auto &&e : result) {
      printf(" %d", e + 1);
    }
    puts("");
  }
}
