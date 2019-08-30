#include <bits/stdc++.h>

static const int MOD = 1e9 + 7;

void update(int &x, int a) { (x += a) %= MOD; }

int main() {
  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) == 3) {
    std::vector<int> three(k);
    three[0] = 3;
    for (int i = 1; i < k; ++i) {
      three[i] = 1LL * three[i - 1] * three[i - 1] % MOD;
    }
    int result = 0;
    for (int _ = 0; _ < n; ++_) {
      std::vector<int> a(m);
      for (int j = 0; j < m; ++j) {
        scanf("%d", &a[j]);
      }
      std::vector<std::vector<int>> dp(k + 1, std::vector<int>(1 << m));
      dp[0][0] = 1;
      for (int i = 0; i < k; ++i) {
        int amask = 0;
        for (int j = 0; j < m; ++j) {
          amask |= (a[j] >> i & 1) << j;
        }
        for (int mask = 0; mask < 1 << m; ++mask) {
          update(dp[i + 1][mask], dp[i][mask]);
          update(dp[i + 1][mask ^ amask], 1LL * three[i] * dp[i][mask] % MOD);
        }
      }
      update(result, dp[k][(1 << m) - 1]);
    }
    printf("%d\n", result);
  }
}
