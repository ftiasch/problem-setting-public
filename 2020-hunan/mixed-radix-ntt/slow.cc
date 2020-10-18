#include <cstdint>
#include <cstdio>
#include <vector>

using u64 = uint64_t;

int main() {
  int n, p, w;
  while (scanf("%d%d%d", &n, &p, &w) == 3) {
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &c[i]);
    }
    int z = 1;
    for (int i = 0; i < n; ++i) {
      int result = 0;
      for (int j = n; j--;) {
        result = ((u64)result * z + c[j]) % p;
      }
      printf("%d%c", result, " \n"[i + 1 == n]);
      z = (u64)z * w % p;
    }
  }
}
