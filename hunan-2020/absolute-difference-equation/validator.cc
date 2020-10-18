#include "testlib.h"

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  int sn = 0;
  while (!inf.eof()) {
    std::string s = inf.readToken("[01?]{1,1000000}", "a");
    sn += s.size();
    ensuref(sn <= 10000000, "sum of all |s| <= 10000000");
    inf.readEoln();
  }
  inf.readEof();
  return 0;
}
