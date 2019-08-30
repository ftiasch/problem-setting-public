#include <bits/stdc++.h>
#include <testlib.h>

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  ensure(argc >= 5);
  int t = std::atoi(argv[1]);
  int N = std::atoi(argv[2]);
  int M = std::atoi(argv[3]);
  int K = std::atoi(argv[4]);
  while (t--) {
    int n = N < 0 ? rnd.next(1, -N) : N;
    int m = N < 0 ? rnd.next(1, -M) : M;
    int k = N < 0 ? rnd.next(1, -K) : K;
    printf("%d %d %d\n", n, m, k);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        printf("%d%c", rnd.next(0, (1 << k) - 1), " \n"[j == m - 1]);
      }
    }
  }
}
