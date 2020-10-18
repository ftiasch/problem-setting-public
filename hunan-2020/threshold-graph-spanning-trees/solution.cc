#include <cstdint>
#include <cstdio>
#include <vector>

using i64 = int64_t;

static const int MOD = 1e9 + 7;

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    std::vector<char> s(n + 1);
    scanf("%s", s.data());
    int result = 1;
    int ones = 0;
    for (int i = n; i-- > 1;) {
      if (s[i] == '1') {
        if (i + 1 < n) {
          result = (i64)result * (i + ones + 1) % MOD;
        }
        ones++;
      } else {
        result = (i64)result * ones % MOD;
      }
    }
    printf("%d\n", result);
  }
}