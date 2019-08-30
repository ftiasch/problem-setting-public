#include <bits/stdc++.h>

static const int K = 32;
static const long long LIMIT = 1e18;

std::array<std::vector<long long>, K> BINOMS;

static int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

static inline long long compare(int n, int k) {
  if (n - k < k) {
    k = n - k;
  }
  // n >= 2 * k
  if (k >= K) {
    return LIMIT;
  }
  if (k == 0) {
    return 1;
  }
  if (k == 1) {
    return n;
  }
  if (k == 2) {
    return 1LL * n * (n - 1) / 2;
  }
  n -= 2 * k;
  if (n >= static_cast<int>(BINOMS[k].size())) {
    return LIMIT;
  }
  return BINOMS[k][n];
}

int main() {
  for (int k = 3; k < K; ++k) {
    uint64_t result = 1;
    int n = k + k;
    for (int i = 0; i < k; ++i) {
      result = result * (n - i) / (i + 1);
    }
    while (result <= LIMIT) {
      BINOMS[k].push_back(result);
      n++;
      int g = gcd(n - k, n);
      result = result / ((n - k) / g) * (n / g);
    }
  }
  std::ios::sync_with_stdio(false);
  int n, k;
  while (std::cin >> n >> k) {
    std::cout << compare(n, k) << std::endl;
  }
}
