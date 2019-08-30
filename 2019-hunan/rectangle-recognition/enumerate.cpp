#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
  assert(argc >= 2);
  int n = std::atoi(argv[1]);
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int msk = 0; msk < 1 << i * j; ++msk) {
        printf("%d %d\n", i, j);
        for (int x = 0; x < i; ++x) {
          for (int y = 0; y < j; ++y) {
            printf("%d", msk >> x * j + y & 1);
          }
          puts("");
        }
        sum += i * j;
      }
    }
  }
  fprintf(stderr, "sum = %d\n", sum);
}
