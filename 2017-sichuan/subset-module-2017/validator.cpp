#include "testlib.h"

int main()
{
    registerValidation();
    int sum_n = 2000000;
    while (!inf.eof()) {
        int n = inf.readInt(1, sum_n, "n");
        sum_n -= n;
        inf.readSpace();
        inf.readInt(1, 2016);
        inf.readEoln();
        for (int i = 0; i < n; ++ i) {
            inf.readInt(1, 2016);
            if (i + 1 < n) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
    }
    inf.readEof();
}
