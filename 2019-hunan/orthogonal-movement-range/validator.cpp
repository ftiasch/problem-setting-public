#include <testlib.h>

int main() {
  registerValidation();
  int tests = 0;
  while (!inf.eof()) {
    for (int i = 0; i < 5; ++i) {
      inf.readInt(1, 1000000000);
      if (i + 1 < 5) {
        inf.readSpace();
      } else {
        inf.readEoln();
      }
    }
    ensure((++tests) <= 100000);
  }
  inf.readEof();
}
