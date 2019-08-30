#include <bits/stdc++.h>

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    std::vector<std::vector<char>> g(n, std::vector<char>(m + 1));
    int x_min = n, x_max = -1, y_min = m, y_max = -1;
    for (int i = 0; i < n; ++i) {
      scanf("%s", g[i].data());
      for (int j = 0; j < m; ++j) {
        if (g[i][j] == '1') {
          x_min = std::min(x_min, i);
          x_max = std::max(x_max, i);
          y_min = std::min(y_min, j);
          y_max = std::max(y_max, j);
        }
      }
    }
    bool ok = x_min <= x_max && y_min <= y_max;
    for (int i = x_min; i <= x_max; ++i) {
      for (int j = y_min; j <= y_max; ++j) {
        ok &= (g[i][j] == '1');
      }
    }
    puts(ok ? "Yes" : "No");
  }
}
