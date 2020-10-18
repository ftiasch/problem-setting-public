#include "testlib.h"

int main() {
  registerValidation();
  int sum_length = 0;
  while (!inf.eof()) {
    int n = inf.readInt(1, 100'000);
    inf.readEoln();
    for (int i = 0; i < n; ++i) {
      sum_length += inf.readToken("[a-z]{1,1000000}").size();
      inf.readEoln();
    }
    ensure(sum_length <= 5'000'000);
  }
  inf.readEof();
}
