#include "testlib.h"

#include <bits/stdc++.h>

int main()
{
    registerValidation();
    int tests = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, 1000000000);
        inf.readSpace();
        inf.readInt(0, n);
        inf.readEoln();
        tests ++;
    }
    ensure(tests <= 10000);
    inf.readEof();
}
