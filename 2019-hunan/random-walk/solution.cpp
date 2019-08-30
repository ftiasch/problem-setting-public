#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

constexpr int inv(int a) {
  return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inv(MOD % a) % MOD;
}

const int PM = 10000;
const int INV_PM = inv(PM);

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

void inv_mat(std::vector<std::vector<int>> &a, int n) {
  for (int j = 0; j < n; ++j) {
    int pivot = j;
    while (pivot < n && !a[pivot][j]) {
      pivot++;
    }
    assert(pivot < n);
    for (int k = 0; k < n + n; ++k) {
      std::swap(a[j][k], a[pivot][k]);
    }
    int s = inv(a[j][j]);
    for (int k = 0; k < n + n; ++k) {
      a[j][k] = 1LL * s * a[j][k] % MOD;
    }
    assert(a[j][j] == 1);
    for (int i = 0; i < n; ++i) {
      if (i != j) {
        s = a[i][j];
        for (int k = 0; k < n + n; ++k) {
          add(a[i][k], MOD - 1LL * s * a[j][k] % MOD);
        }
      }
    }
  }
}

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    std::vector<std::vector<int>> prob(n, std::vector<int>(n + m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n + m; ++j) {
        scanf("%d", &prob[i][j]);
      }
    }
    std::vector<std::vector<int>> a(n + m, std::vector<int>(n + m << 1));
    for (int i = 0; i < n + m; ++i) {
      for (int j = 0; j < n + m; ++j) {
        if (i == j) {
          a[i][j] = 1;
        }
        if (i < n) {
          add(a[i][j], MOD - 1LL * prob[i][j] * INV_PM % MOD);
        }
      }
      a[i][n + m + i] = 1;
    }
    inv_mat(a, n + m);
    for (int i = 0; i < m; ++i) {
      printf("%d%c", a[0][n + m + n + i], " \n"[i == m - 1]);
    }
  }
}
