#include "testlib.h"

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int T = std::atoi(argv[1]);
  int n = std::atoi(argv[2]);
  while (T--) {
    std::vector<char> s(n + 1);
    s[n] = '\0';
    for (int i = 0; i < n; ++i) {
      s[i] = "01"[rnd.next(0, 1)];
    }
    s[n - 1] = '1';
    printf("%d\n", n);
    puts(s.data());
  }
}