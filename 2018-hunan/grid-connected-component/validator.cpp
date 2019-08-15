#include "testlib.h"

int main()
{
    registerValidation();
    int sum_q = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, 1000000000);
        inf.readSpace();
        int m = inf.readInt(1, 1000000000);
        inf.readSpace();
        int q = inf.readInt(1, 100000);
        inf.readEoln();
        for (int i = 0; i < q; ++ i) {
            int t = inf.readInt(1, 2);
            inf.readSpace();
            int max = t == 1 ? n : m;
            int l = inf.readInt(1, max);
            inf.readSpace();
            inf.readInt(l, max);
            inf.readEoln();
        }
        sum_q += q;
    }
    ensure(sum_q <= 500000);
    inf.readEof();
}
