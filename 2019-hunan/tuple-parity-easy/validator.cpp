#include <bits/stdc++.h>
#include <testlib.h>

int main() {
  registerValidation();
  int tests = 0;
  int large = 0;
  while (!inf.eof()) {
    int n = inf.readInt(1, 10000);
    inf.readSpace();
    int m = inf.readInt(1, 10);
    inf.readSpace();
    int k = inf.readInt(1, 30);
    inf.readEoln();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        inf.readInt(0, (1 << k) - 1);
        if (j + 1 < m) {
          inf.readSpace();
        } else {
          inf.readEoln();
        }
      }
    }
    if (n > 1000 || m > 5) {
      ensure(++large <= 1);
    }
    ensure(++tests <= 100);
  }
  inf.readEof();
}
