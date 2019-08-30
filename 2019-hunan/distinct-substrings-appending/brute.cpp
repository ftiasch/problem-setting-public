#include <bits/stdc++.h>

static const int MOD = 1e9 + 7;

int solve(std::vector<int> s, int a) {
  if (a) {
    s.push_back(a);
  }
  std::vector<std::vector<int>> ss;
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    std::vector<int> u;
    for (int j = i; j < static_cast<int>(s.size()); ++j) {
      u.push_back(s[j]);
      ss.push_back(u);
    }
  }
  std::sort(ss.begin(), ss.end());
  return (std::unique(ss.begin(), ss.end()) - ss.begin()) % MOD;
}

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    std::vector<int> s(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &s[i]);
    }
    int base = solve(s, 0);
    int three = 1;
    int result = 0;
    for (int i = 1; i <= m; ++i) {
      three = 3LL * three % MOD;
      result ^= 1LL * three * (solve(s, i) + MOD - base) % MOD;
    }
    printf("%d\n", result);
  }
}
