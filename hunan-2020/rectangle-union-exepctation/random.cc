#include "testlib.h"

#include <algorithm>
#include <cstdlib>

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int T = std::atoi(argv[1]);
  const int m = std::atoi(argv[2]);

  while (T--) {
    int a = rnd.next(1, m);
    int b = rnd.next(1, m);
    printf("%d %d\n", a, b);
    for (int i = 0; i < 2; ++i) {
      while (true) {
        int x1 = rnd.next(1, m);
        int x2 = rnd.next(1, m);
        if (x1 != x2) {
          if (x1 > x2) {
            std::swap(x1, x2);
          }
          printf("%d %d%c", x1, x2, " \n"[i == 1]);
          break;
        }
      }
    }
  }
}
