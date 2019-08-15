#include "testlib.h"

int main()
{
    registerValidation();
    int sum_n = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, 100000);
        inf.readEoln();
        for (int i = 0; i < n; ++ i) {
            inf.readInt(0, n);
            if (i + 1 < n) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
        sum_n += n;
    }
    fprintf(stderr, "sum n = %d\n", sum_n);
    ensure(sum_n <= 250000);
    inf.readEof();
}
