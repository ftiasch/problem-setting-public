#include <testlib.h>

int main() {
  registerValidation();
  int sum_n = 0;
  int sum_m = 0;
  while (!inf.eof()) {
    int n = inf.readInt(1, 100000);
    inf.readSpace();
    int m = inf.readInt(1, 100000);
    inf.readEoln();
    for (int _ = 0; _ < m; ++_) {
      int a = inf.readInt(1, n);
      inf.readSpace();
      int b = inf.readInt(1, n);
      inf.readEoln();
      ensure(a != b);
    }
    ensure((sum_n += n) <= 500000);
    ensure((sum_m += m) <= 500000);
  }
  inf.readEof();
}
