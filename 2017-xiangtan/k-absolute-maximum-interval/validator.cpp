#include "testlib.h"

int main()
{
    registerValidation();
    int sum_n = 0;
    while (!inf.eof()) {
        int n = inf.readInt(2, 100000, "n");
        sum_n += n;
        ensure(sum_n <= 2000000);
        inf.readSpace();
        int m = inf.readInt(1, n + 1 >> 1, "m");
        inf.readSpace();
        inf.readInt(1, 10000, "c");
        inf.readEoln();
        for (int i = 0; i < n; ++ i) {
            inf.readInt(-10000, 10000);
            if (i + 1 < n) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
    }
    inf.readEof();
}
