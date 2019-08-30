#include <testlib.h>

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  ensure(argc >= 3);
  int T = std::atoi(argv[1]);
  int N = std::atoi(argv[2]);
  while (T--) {
    int n = N < 0 ? rnd.next(1, -N) : N;
    int m = N < 0 ? rnd.next(1, -N) : N;
    int x_min = rnd.next(1, n);
    int x_max = rnd.next(1, n);
    if (x_min > x_max) {
      std::swap(x_min, x_max);
    }
    int y_min = rnd.next(1, m);
    int y_max = rnd.next(1, m);
    if (y_min > y_max) {
      std::swap(y_min, y_max);
    }
    int x0 = 0, y0 = m;
    if (rnd.next(0, 1)) {
      x0 = rnd.next(1, n);
      y0 = rnd.next(1, m);
    }
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int c = 0;
        if (x_min <= i && i <= x_max && y_min <= j && j <= y_max) {
          c = 1;
        }
        if (i == x0 && j == y0) {
          c ^= 1;
        }
        printf("%d", c);
      }
      puts("");
    }
  }
}
