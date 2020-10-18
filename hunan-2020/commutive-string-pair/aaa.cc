#include "testlib.h"

#include <cstdlib>
#include <vector>

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  const int n = std::atoi(argv[1]);
  const int m = std::atoi(argv[2]);
  const int w = std::atoi(argv[3]);
  std::vector<int> length(n, 1);
  for (int i = n; i < m; ++i) {
    length[rnd.wnext(0, n - 1, w)]++;
  }
  shuffle(length.begin(), length.end());
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < length[i]; ++j) {
      putchar('a');
    }
    puts("");
  }
}
