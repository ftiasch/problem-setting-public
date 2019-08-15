#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(1, 100000);
    inf.readSpace();
    int m = inf.readInt(1, 1000);
    inf.readEoln();
    for (int i = 0; i < n; ++ i) {
        inf.readInt(1, m);
        inf.readSpace();
        inf.readInt(1, m);
        inf.readEoln();
    }
    inf.readEof();
}
