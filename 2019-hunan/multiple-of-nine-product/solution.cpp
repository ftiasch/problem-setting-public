#include <bits/stdc++.h>

static const int MOD = 1e9 + 7;

void update(int &x, int a) { (x += a) %= MOD; }

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    std::vector<int> left(n + 1, 0);
    for (int i = 0, l, r; i < m; ++i) {
      scanf("%d%d", &l, &r);
      left[r] = std::max(left[r], l);
    }
    std::vector<std::vector<std::vector<int>>> dp(
        n + 1, std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1)));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        for (int k = 0; k <= j; ++k) {
          if (left[i] <= k) {
            update(dp[i + 1][j][k], 6LL * dp[i][j][k] % MOD);
            update(dp[i + 1][i + 1][j], 2LL * dp[i][j][k] % MOD);
            update(dp[i + 1][i + 1][i + 1], 2LL * dp[i][j][k] % MOD);
          }
        }
      }
    }
    int result = 0;
    for (int j = 0; j <= n; ++j) {
      for (int k = left[n]; k <= j; ++k) {
        update(result, dp[n][j][k]);
      }
    }
    printf("%d\n", result);
  }
}
