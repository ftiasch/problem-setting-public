#include "testlib.h"

int main() {
  registerValidation();
  int sum_n = 0;
  while (!inf.eof()) {
    int n = inf.readInt(1, 100'000);
    inf.readEoln();
    inf.readToken(format("[012]{%d}", n));
    inf.readEoln();
    ensure((sum_n += n) <= 1'000'000);
  }
  inf.readEof();
}
