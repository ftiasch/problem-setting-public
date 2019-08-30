#include <bits/stdc++.h>

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    std::vector<std::vector<char>> g(n + 2, std::vector<char>(m + 2, '0'));
    for (int i = 1; i <= n; ++i) {
      std::vector<char> buffer(m + 1);
      scanf("%s", buffer.data());
      std::copy(buffer.begin(), buffer.end(), g[i].begin() + 1);
    }
    std::array<int, 5> count;
    std::fill(count.begin(), count.end(), 0);
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        int c = 0;
        for (int x = 0; x < 2; ++x) {
          for (int y = 0; y < 2; ++y) {
            c += (g[i + x][j + y] == '1');
          }
        }
        count[c]++;
      }
    }
    bool ok = true;
    ok &= count[1] == 4;
    ok &= count[3] == 0;
    puts(ok ? "Yes" : "No");
  }
}
