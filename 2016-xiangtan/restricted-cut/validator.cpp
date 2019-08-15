#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(6, 50);
    inf.readSpace();
    int m = inf.readInt(0, 500);
    inf.readEoln();
    for (int _ = 0; _ < m; ++ _) {
        int a = inf.readInt(1, n);
        inf.readSpace();
        int b = inf.readInt(1, n);
        inf.readSpace();
        inf.readInt(1, 1000);
        inf.readEoln();
        ensure(a != b);
    }
    inf.readEof();
}
