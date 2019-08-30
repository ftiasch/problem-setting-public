#include <testlib.h>

int main() {
  registerValidation();
  int tests = 0;
  while (!inf.eof()) {
    int n = inf.readInt(1, 10);
    inf.readSpace();
    int m = inf.readInt(1, 10);
    inf.readEoln();
    for (int i = 0; i < n; ++i) {
      inf.readToken(format("[01]{%d}", m));
      inf.readEoln();
    }
    ensure(++tests <= 1000);
  }
  inf.readEof();
}
