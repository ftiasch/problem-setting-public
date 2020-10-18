#include "testlib.h"

int main() {
  registerValidation();
  int tests = 0;
  while (!inf.eof()) {
    inf.readInt(1, 1'000'000'000, "a");
    inf.readSpace();
    inf.readInt(1, 1'000'000'000, "b");
    inf.readEoln();
    int x1 = inf.readInt(1, 1'000'000'000, "x1");
    inf.readSpace();
    inf.readInt(x1 + 1, 1'000'000'000, "x2");
    inf.readSpace();
    int y1 = inf.readInt(1, 1'000'000'000, "y1");
    inf.readSpace();
    inf.readInt(y1 + 1, 1'000'000'000, "y2");
    inf.readEoln();
    ensure((++tests) <= 10'000);
  }
  inf.readEof();
}
