#include "testlib.h"

int main()
{
    registerValidation();
    int sum_n = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, 100000);
        inf.readSpace();
        auto m = inf.readToken(format("[01]{1,%d}", n));
        ensure(m.size() == 1 || m[0] != '0');
        inf.readEoln();
        sum_n += n;
    }
    fprintf(stderr, "sum n = %d\n", sum_n);
    ensure(sum_n <= 250000);
    inf.readEof();
}
