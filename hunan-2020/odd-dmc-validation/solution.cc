#include <algorithm>
#include <cstdio>
#include <vector>

bool check(int n, int m, const std::vector<std::vector<int>> &a) {
  if (n > 2) {
    return false;
  }
  if (n == 1) {
    return true;
  }
  int result = 0;
  for (int i = 0; i < m; ++i) {
    result += std::abs(a[0][i] - a[1][i]);
  }
  return result & 1;
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
