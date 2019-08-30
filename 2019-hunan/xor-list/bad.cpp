#include <bits/stdc++.h>
#include <testlib.h>

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  ensure(argc >= 3);
  int T = std::atoi(argv[1]);
  int N = std::atoi(argv[2]);
  while (T--) {
    int n = N < 0 ? rnd.next(1, -N) : N;
    printf("%d %d\n", n, n - 1);
    int last = n;
    for (int i = n - 1; i >= 1; --i) {
      if (rnd.next(0, 1) || i == 1) {
        printf("%d %d\n", i, last);
        last = i;
      } else {
        printf("%d %d\n", last, i);
      }
    }
  }
}
