#include <bits/stdc++.h>

int main() {
  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) == 3) {
    std::vector<int> count(1 << k);
    for (int i = 0; i < n; ++i) {
      std::vector<int> a(m);
      for (int j = 0; j < m; ++j) {
        scanf("%d", &a[j]);
      }
      for (int x = 0; x < 1 << k; ++x) {
        bool parity = true;
        for (int j = 0; j < m; ++j) {
          parity &= __builtin_parity(a[j] & x);
        }
        count[x] += parity;
      }
    }
    int result = 0;
    int three = 1;
    for (int msk = 0; msk < 1 << k; ++msk) {
      result ^= 1LL * three * count[msk] % MOD;
      three = 3LL * three % MOD;
    }
    printf("%d\n", result);
  }
}
