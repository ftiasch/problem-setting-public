#include "testlib.h"

const char *s = "01?";

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  int n = std::atoi(argv[1]);
  int total = 1;
  for (int i = 0; i < n; ++i)
    total *= 3;
  for (int mask = 0; mask < total; ++mask) {
    for (int i = 0, m = mask; i < n; ++i) {
      putchar(s[m % 3]);
      m /= 3;
    }
    puts("");
  }
  return 0;
}
