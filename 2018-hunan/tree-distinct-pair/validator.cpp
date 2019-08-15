#include <bits/stdc++.h>

#include "testlib.h"

int main()
{
    registerValidation();
    int sum_n = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, 100000);
        inf.readEoln();
        for (int i = 2; i <= n; ++ i) {
            inf.readInt(1, i - 1);
            if (i < n) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
        for (int i = 0; i < n; ++ i) {
            inf.readInt(1, n);
            if (i + 1 < n) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
        sum_n += n;
    }
    ensure(sum_n <= 500000);
    inf.readEof();
}
