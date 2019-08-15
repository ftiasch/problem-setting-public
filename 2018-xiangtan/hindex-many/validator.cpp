#include "testlib.h"

#include <bits/stdc++.h>

int main()
{
    registerValidation();
    int sum_n = 0;
    int sum_q = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, 100000);
        inf.readSpace();
        int q = inf.readInt(1, 100000);
        inf.readEoln();
        for (int i = 0; i < n; ++ i) {
            inf.readInt(1, n);
            if (i + 1 < n) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
        for (int i = 0; i < q; ++ i) {
            int l = inf.readInt(1, n);
            inf.readSpace();
            inf.readInt(l, n);
            inf.readEoln();
        }
        sum_n += n;
        sum_q += q;
    }
    ensure(sum_n <= 250000);
    ensure(sum_q <= 250000);
    inf.readEof();
}
