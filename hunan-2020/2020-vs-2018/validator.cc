#include "testlib.h"

int main() {
  registerValidation();
  int tests = 0;
  while (!inf.eof()) {
    int n = inf.readInt(1, 50);
    inf.readSpace();
    int m = inf.readInt(1, 50);
    inf.readEoln();
    for (int i = 0; i < n; ++i) {
      auto s = inf.readToken();
      ensure(s.size() == m);
      for (int j = 0; j < m; ++j) {
        ensure(s[j] == '.' || s[j] == 'o');
      }
      inf.readEoln();
    }
    ensure((++tests) <= 100);
  }
  inf.readEof();
}
