#include <bits/stdc++.h>

using Long = long long;

static const int MOD = 1e9 + 7;

int solve(int n, int a[4]) {
  int result = 1;
  for (int k = 0; k < 4; ++k) {
    int x = a[k];
    int y = a[k + 1 & 3];
    result += (n * (n - 1LL) / 2 % MOD * x % MOD * y + 1LL * n * x) % MOD;
    if (result >= MOD) {
      result -= MOD;
    }
  }
  return result;
}

int main() {
  int n, a[4];
  while (scanf("%d%d%d%d%d", &n, a, a + 1, a + 2, a + 3) == 5) {
    printf("%d\n", solve(n, a));
  }
}
