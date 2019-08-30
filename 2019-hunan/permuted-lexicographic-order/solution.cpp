#include <bits/stdc++.h>

std::vector<int> solve(int n, int m,
                       const std::vector<std::vector<int>> &perm) {
  std::vector<int> count(m);
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i + 1 < n; ++i) {
      count[j] += perm[i][j] > perm[i + 1][j];
    }
  }
  std::vector<int> order;
  std::vector<bool> seperated(n - 1), selected(m);
  for (int _ = 0; _ < m; ++_) {
    int j = 0;
    while (j < m && !(!selected[j] && count[j] == 0)) {
      j++;
    }
    if (j == m) {
      return {};
    }
    selected[j] = true;
    for (int i = 0; i + 1 < n; ++i) {
      if (perm[i][j] < perm[i + 1][j] && !seperated[i]) {
        seperated[i] = true;
        for (int k = 0; k < m; ++k) {
          count[k] -= perm[i][k] > perm[i + 1][k];
        }
      }
    }
    order.push_back(j);
  }
  return order;
}

bool check(int n, int m, const std::vector<std::vector<int>> &perm,
           const std::vector<int> &order) {
  for (int i = 0; i + 1 < n; ++i) {
    for (int j : order) {
      if (perm[i][j] < perm[i + 1][j]) {
        break;
      }
      if (perm[i][j] > perm[i + 1][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    std::vector<std::vector<int>> perm(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &perm[i][j]);
      }
    }
    auto result = solve(n, m, perm);
    if (result.empty()) {
      puts("-1");
    } else {
      for (int j = 0; j < m; ++j) {
        printf("%d%c", result[j] + 1, " \n"[j == m - 1]);
      }
      assert(check(n, m, perm, result));
    }
  }
}
