#include "testlib.h"

int main()
{
    registerValidation();
    int sum_n = 0;
    int sum_m = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, 500000);
        sum_n += n;
        inf.readSpace();
        int m = inf.readInt(1, 500000);
        sum_m += m;
        inf.readSpace();
        int l = inf.readInt(0, n + m);
        inf.readSpace();
        inf.readInt(l, n + m);
        inf.readEoln();
        for (int i = 0; i <= n; ++ i) {
            inf.readInt(0, 1000000000);
            if (i + 1 <= n) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
        for (int i = 0; i <= m; ++ i) {
            inf.readInt(0, 1000000000);
            if (i + 1 <= m) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
    }
    ensure(sum_n <= 1000000 && sum_m <= 1000000);
    inf.readEof();
}
