#include <bits/stdc++.h>

const int MOD = 1e9 + 7;
const int INV_PM = 285700002;

int power(int a, int n) {
  int result = 1;
  while (n) {
    if (n & 1) {
      result = 1LL * result * a % MOD;
    }
    a = 1LL * a * a % MOD;
    n >>= 1;
  }
  return result;
}

void update(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
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
    for (int t = 0; t < m; ++t) {
      std::vector<std::vector<int>> a(n, std::vector<int>(n + 1));
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          a[i][j] = 1LL * INV_PM * prob[i][j] % MOD;
        }
        update(a[i][i], MOD - 1);
        a[i][n] = (MOD - 1LL * INV_PM * prob[i][n + t] % MOD) % MOD;
      }
      for (int j = 0; j < n; ++j) {
        int pivot = j;
        while (pivot < n && !a[pivot][j]) {
          pivot++;
        }
        assert(pivot < n);
        std::swap(a[j], a[pivot]);
        int s = power(a[j][j], MOD - 2);
        for (int k = 0; k <= n; ++k) {
          a[j][k] = 1LL * s * a[j][k] % MOD;
        }
        assert(a[j][j] == 1);
        for (int i = 0; i < n; ++i) {
          if (i != j) {
            s = a[i][j];
            for (int k = 0; k <= n; ++k) {
              update(a[i][k], MOD - 1LL * s * a[j][k] % MOD);
            }
          }
        }
      }
      printf("%d%c", a[0][n], " \n"[t == m - 1]);
    }
  }
}
