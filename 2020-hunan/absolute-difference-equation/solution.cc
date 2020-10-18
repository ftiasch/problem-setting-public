#include <cstdio>
#include <cstring>
#include <vector>

using i64 = long long;

const int N = 1e6 + 10;
const int mod = 1e9 + 7;

char s[N];

int main() {
  while (scanf("%s", s) == 1) {
    int n = strlen(s);
    std::vector<int> cnt(n);
    int f[2];
    f[0] = 1;
    f[1] = 0;
    for (int i = 1; i < n; ++i) {
      cnt[i] = cnt[i - 1] + __builtin_ctz(i);
    }
    for (int i = 0; i < n; ++i) {
      int e = (cnt[n - 1] - cnt[i] - cnt[n - 1 - i] == 0);
      std::vector<int> v;
      if (s[i] == '0')
        v = {0};
      else if (s[i] == '1')
        v = {1};
      else
        v = {0, 1};
      i64 g[2] = {0, 0};
      for (auto x : v)
        for (int o = 0; o < 2; ++o) {
          g[o ^ (x & e)] += f[o];
        }
      f[0] = g[0] % mod;
      f[1] = g[1] % mod;
    }
    printf("%d\n", f[1]);
  }
  return 0;
}
