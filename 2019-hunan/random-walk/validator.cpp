#include <testlib.h>

const int N = 500;
const int PM = 10000;

int main() {
  registerValidation();
  int tests = 0;
  int large = 0;
  while (!inf.eof()) {
    int n = inf.readInt(1, N - 1);
    inf.readSpace();
    int m = inf.readInt(1, N - n);
    inf.readEoln();
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = 0; j < n + m; ++j) {
        sum += inf.readInt(1, PM);
        if (j + 1 < n + m) {
          inf.readSpace();
        } else {
          inf.readEoln();
        }
      }
      ensure(sum == PM);
    }
    ensure(++tests <= 100);
    if (n + m > 50) {
      ensure(++large <= 1);
    }
  }
  inf.readEof();
}
