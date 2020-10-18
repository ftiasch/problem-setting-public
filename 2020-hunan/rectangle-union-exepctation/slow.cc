#include <algorithm>
#include <cstdint>
#include <cstdio>

static const int MOD = 1e9 + 7;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int main() {
  int a, b;
  while (scanf("%d%d", &a, &b) == 2) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
    int area = (uint64_t)(x2 - x1) * (y2 - y1) % MOD;
    int result = 0;
    for (int i = 1; i <= a; ++i) {
      for (int j = 1; j <= b; ++j) {
        add(result, area);
        add(result, (uint64_t)i * j % MOD);
        add(result, MOD - (uint64_t)std::max(std::min(i, x2) - x1, 0) *
                              std::max(std::min(j, y2) - y1, 0) % MOD);
      }
    }
    printf("%d\n", result);
  }
}
