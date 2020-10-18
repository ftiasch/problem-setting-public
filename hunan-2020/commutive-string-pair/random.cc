#include "testlib.h"

#include <cstdlib>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int T = std::atoi(argv[1]);
  const int n = std::atoi(argv[2]);
  const int m = std::atoi(argv[3]);
  const int w = std::atoi(argv[4]);
  const int c = std::atoi(argv[5]);
  const int k = std::atoi(argv[6]);

  int max_period = m / n;
  while (T--) {
    int period = rnd.next(1, max_period);

    std::vector<int> exps(n, 1);
    for (int i = n; i < m / period; ++i) {
      exps[rnd.wnext(0, n - 1, w)]++;
    }
    shuffle(exps.begin(), exps.end());

    std::vector<std::string> patterns(k);
    patterns[0] = std::string(period, ' ');
    for (int i = 0; i < period; ++i) {
      patterns[0][i] = 'a' + rnd.next(0, c - 1);
    }
    for (int i = 1; i < k; ++i) {
      patterns[i] = patterns[i - 1];
      int j = rnd.next(0, period - 1);
      patterns[i][j] = 'a' + rnd.next(0, c - 1);
    }

    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
      auto &&p = patterns[rnd.next(0, k - 1)];
      for (int j = 0; j < exps[i]; ++j) {
        printf("%s", p.c_str());
      }
      puts("");
    }
  }
}
