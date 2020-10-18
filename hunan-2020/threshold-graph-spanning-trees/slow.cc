#include <algorithm>
#include <cstdio>
#include <vector>

static const int MOD = 1e9 + 7;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int det(int n, std::vector<std::vector<int>> &a) {
  int result = 1;
  for (int j = 0; j < n; ++j) {
    int pivot = j;
    while (pivot < n && !a[pivot][j]) {
      pivot++;
    }
    if (pivot == n) {
      return 0;
    }
    if (j != pivot) {
      std::swap(a[j], a[pivot]);
      result = MOD - result;
    }
    for (int i = j + 1; i < n; ++i) {
      while (a[i][j]) {
        uint64_t t = a[j][j] / a[i][j];
        for (int k = j; k < n; ++k) {
          add(a[j][k], MOD - t * a[i][k] % MOD);
        }
        std::swap(a[i], a[j]);
        result = MOD - result;
      }
    }
    result = 1LL * result * a[j][j] % MOD;
  }
  return result;
}

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    std::vector<char> s(n + 1);
    scanf("%s", s.data());
    std::vector<std::vector<int>> laplacian(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        for (int j = 0; j < i; ++j) {
          add(laplacian[i][i], 1);
          add(laplacian[j][j], 1);
          add(laplacian[i][j], MOD - 1);
          add(laplacian[j][i], MOD - 1);
        }
      }
    }
    printf("%d\n", det(n - 1, laplacian));
  }
}
