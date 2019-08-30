#include <bits/stdc++.h>

static const int MOD = 1e9 + 7;

static const int DELTA_X[] = {1, 0, -1, 0};
static const int DELTA_Y[] = {0, 1, 0, -1};

int solve(int n, int a[4]) {
  std::set<std::pair<int, int>> s{{0, 0}};
  while (n--) {
    __typeof(s) ns;
    for (auto &&p : s) {
      for (int k = 0; k < 4; ++k) {
        for (int i = 0; i <= a[k]; ++i) {
          ns.emplace(p.first + DELTA_X[k] * i, p.second + DELTA_Y[k] * i);
        }
      }
    }
    s.swap(ns);
  }
  return s.size() % MOD;
}
int main() {
  int n, a[4];
  while (scanf("%d%d%d%d%d", &n, a, a + 1, a + 2, a + 3) == 5) {
    printf("%d\n", solve(n, a));
  }
}
