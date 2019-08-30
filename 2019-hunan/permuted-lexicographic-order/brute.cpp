#include <bits/stdc++.h>

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    std::vector<std::vector<int>> perm(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &perm[i][j]);
      }
    }
    std::vector<int> result;
    std::vector<int> order(m);
    std::iota(order.begin(), order.end(), 0);
    do {
      bool ok = true;
      for (int i = 0; i + 1 < n && ok; ++i) {
        for (int j : order) {
          if (perm[i][j] < perm[i + 1][j]) {
            break;
          }
          if (perm[i][j] > perm[i + 1][j]) {
            ok = false;
            break;
          }
        }
      }
      if (ok) {
        result = order;
        break;
      }
    } while (std::next_permutation(order.begin(), order.end()));
    if (result.empty()) {
      puts("-1");
    } else {
      for (int j = 0; j < m; ++j) {
        printf("%d%c", result[j] + 1, " \n"[j == m - 1]);
      }
    }
  }
}
