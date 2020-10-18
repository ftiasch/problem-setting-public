#include "testlib.h"

#include <cstdlib>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int T = std::atoi(argv[1]);
  const int n = std::atoi(argv[2]);
  const int m = std::atoi(argv[3]);

  while (T--) {
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        printf("%d%c", rnd.next(0, 9), " \n"[j + 1 == m]);
      }
    }
  }
}
