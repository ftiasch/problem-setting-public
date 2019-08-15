#include "testlib.h"

#include <bits/stdc++.h>

const int INF = 1000000000;

int main()
{
    registerValidation();
    int tests = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, 50);
        inf.readSpace();
        inf.readInt(1, INF);
        inf.readEoln();
        for (int i = 0; i < n; ++ i) {
            inf.readInt(0, INF);
            if (i + 1 < n) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
        for (int i = 0; i < n; ++ i) {
            inf.readInt(0, INF);
            if (i + 1 < n) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
        tests ++;
    }
    ensure(tests <= 10);
    inf.readEof();
}
