#include <bits/stdc++.h>

static inline int signum(long long x) { return x < 0 ? -1 : x > 0; }

static inline int compare(int n, int k, long long a) {
  if (n - k < k) {
    k = n - k;
  }
  long double result = 1;
  for (int i = 0; i < k; ++i) {
    result = result * (n - i) / (i + 1);
    if (result > a + 1e-9) {
      return 1;
    }
  }
  return signum(static_cast<long long>(round(result)) - a);
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  long long a;
  while (std::cin >> n >> k >> a) {
    int s = compare(n, k, a);
    if (s == 0) {
      puts("=");
    } else {
      puts(s < 0 ? "<" : ">");
    }
  }
}
