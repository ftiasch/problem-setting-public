#include <testlib.h>

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  ensure(argc >= 4);
  int T = std::atoi(argv[1]);
  int N = std::atoi(argv[2]);
  int M = std::atoi(argv[3]);
  while (T--) {
    int n = N < 0 ? rnd.next(1, -N) : N;
    int a[4];
    for (int i = 0; i < 4; ++i) {
      a[i] = M < 0 ? rnd.next(1, -M) : M;
    }
    printf("%d %d %d %d %d\n", n, a[0], a[1], a[2], a[3]);
  }
}
