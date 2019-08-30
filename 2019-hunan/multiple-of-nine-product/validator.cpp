#include <testlib.h>

int main() {
  registerValidation();
  int tests = 0;
  while (!inf.eof()) {
    int n = inf.readInt(1, 50);
    inf.readSpace();
    int m = inf.readInt(1, 50);
    inf.readEoln();
    for (int i = 0; i < m; ++i) {
      int l = inf.readInt(1, n);
      inf.readSpace();
      inf.readInt(l, n);
      inf.readEoln();
    }
    ensure(++tests <= 100);
  }
  inf.readEof();
}
