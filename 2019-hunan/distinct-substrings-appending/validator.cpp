#include <testlib.h>

int main() {
  registerValidation();
  int sum_n = 0;
  int sum_m = 0;
  while (!inf.eof()) {
    int n = inf.readInt(1, 1000000);
    inf.readSpace();
    int m = inf.readInt(1, 1000000);
    inf.readEoln();
    for (int i = 0; i < n; ++i) {
      inf.readInt(1, m);
      if (i + 1 < n) {
        inf.readSpace();
      } else {
        inf.readEoln();
      }
    }
    ensure((sum_n += n) <= 5000000);
    ensure((sum_m += m) <= 5000000);
  }
  inf.readEof();
}
