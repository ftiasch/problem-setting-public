#include <cstdint>
#include <cstdio>
#include <algorithm>

static const int MOD = 1e9 + 7;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int sum(int a, int b)
{
  return (uint64_t)(a + b) * (b - a + 1) / 2 % MOD;
}

int solve(int a, int x1, int x2)
{
  int result = 0;
  // if i < x1, i + (x1 - x2)
  // if x1 <= i < x2, x2
  // if x2 <= i, i
  if (x2 <= a) {
    add(result, sum(x2, a));
  }
}

int main() {
  int a, b;
  while (scanf("%d%d", &a, &b) == 2) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
    printf("%d\n", (int)((uint64_t)solve(a, x1, x2) * solve(b, y1, y2) % MOD));
  }
}
