#include "testlib.h"

int main() {
  registerValidation();
  int tests = 0;
  while (!inf.eof()) {
    int y[3];
    for (int i = 0; i < 3; ++i) {
      int x = inf.readInt(0, 1'000'000'000);
      inf.readSpace();
      inf.readInt(x + 1, 1'000'000'000);
      inf.readSpace();
      y[i] = inf.readInt(0, 1'000'000'000);
      inf.readEoln();
    }
    ensure(y[0] < y[1] && y[1] < y[2]);
    ensure((++tests) <= 10'000);
  }
  inf.readEof();
}
