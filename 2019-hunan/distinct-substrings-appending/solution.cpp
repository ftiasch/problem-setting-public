#include <bits/stdc++.h>

static const int MOD = 1e9 + 7;

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    std::vector<int> s(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &s[i]);
      s[i]--;
    }
    std::reverse(s.begin(), s.end());
    std::vector<int> z(n + 1);
    for (int i = 1, j = 0; i < n; ++i) {
      if (i < j + z[j]) {
        z[i] = std::min(j + z[j] - i, z[i - j]);
      }
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
        z[i]++;
      }
    }
    std::vector<int> best(m);
    for (int i = 0; i < n; ++i) {
      best[s[i]] = std::max(best[s[i]], 1 + z[i + 1]);
    }
    int three = 1;
    int result = 0;
    for (int i = 0; i < m; ++i) {
      three = 3LL * three % MOD;
      result ^= 1LL * three * (n + 1 - best[i]) % MOD;
      assert(best[i] <= n + 1);
    }
    printf("%d\n", result);
  }
}
