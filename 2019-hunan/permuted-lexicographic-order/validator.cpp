#include <testlib.h>

int main() {
  registerValidation();
  int sum = 0;
  while (!inf.eof()) {
    int n = inf.readInt(1, 2000);
    inf.readSpace();
    int m = inf.readInt(1, 2000);
    inf.readEoln();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        inf.readInt(1, 1000000000);
        if (j + 1 < m) {
          inf.readSpace();
        } else {
          inf.readEoln();
        }
      }
    }
    ensure((sum += n * m) <= 10000000);
  }
  inf.readEof();
}
