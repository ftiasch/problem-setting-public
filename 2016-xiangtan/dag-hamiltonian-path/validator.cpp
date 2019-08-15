#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(2, 100000);
    inf.readSpace();
    int m = inf.readInt(0, 100000);
    inf.readEoln();
    for (int i = 0; i < m; ++ i) {
        int a = inf.readInt(1, n);
        inf.readSpace();
        int b = inf.readInt(1, n);
        inf.readSpace();
        inf.readInt(1, 10000);
        inf.readEoln();
        ensure(a < b);
    }
    inf.readEof();
}
