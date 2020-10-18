#include <algorithm>
#include <cstdio>
#include <vector>

bool check(int n, int m, const std::vector<std::vector<int>> &a) {
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int result = 0;
      for (int k = 0; k < m; ++k) {
        result += std::abs(a[i][k] - a[j][k]);
      }
      if (~result & 1) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    puts(check(n, m, a) ? "Yes" : "No");
  }
}
