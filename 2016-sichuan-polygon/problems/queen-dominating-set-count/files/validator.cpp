#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(1, 1000000000);
    inf.readSpace();
    int m = inf.readInt(1, 1000000000);
    inf.readSpace();
    int k = inf.readInt(1, 8);
    ensure(k <= 1LL * n * m);
    inf.readEoln();
    inf.readEof();
}
