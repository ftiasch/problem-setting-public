#include <testlib.h>

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  ensure(argc >= 4);
  int T = std::atoi(argv[1]);
  int N = std::atoi(argv[2]);
  int M = std::atoi(argv[3]);
  while (T--) {
    int n = N < 0 ? rnd.next(1, -N) : N;
    int m = M < 0 ? rnd.next(1, -M) : M;
    printf("%d %d\n", n, m);
    for (int i = 0; i < m; ++i) {
      int l = rnd.next(1, n);
      int r = rnd.next(1, n);
      if (l > r) {
        std::swap(l, r);
      }
      printf("%d %d\n", l, r);
    }
  }
}
