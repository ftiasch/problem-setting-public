#include <bits/stdc++.h>
#include <testlib.h>

int main() {
  registerValidation();
  int tests = 0;
  while (!inf.eof()) {
    inf.readToken("[0-9]{1,50}");
    inf.readEoln();
    ensure((++tests) <= 100);
  }
  inf.readEof();
}
