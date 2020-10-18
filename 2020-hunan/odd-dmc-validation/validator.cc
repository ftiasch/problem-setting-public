#include "testlib.h"

int main() {
  registerValidation();
  int sum_nm = 0;
  while (!inf.eof()) {
    int n = inf.readInt(1, 1'000);
    inf.readSpace();
    int m = inf.readInt(1, 1'000);
    inf.readEoln();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        inf.readInt(0, 9);
        if (j + 1 < m) {
          inf.readSpace();
        } else {
          inf.readEoln();
        }
      }
    }
    ensure((sum_nm += n * m) <= 2'000'000);
  }
  inf.readEof();
}
