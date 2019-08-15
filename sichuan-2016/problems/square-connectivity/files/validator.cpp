#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(1, 100000);
    inf.readSpace();
    int m = inf.readInt(1, 100000);
    inf.readEoln();
    for (int _ = 0; _ < m; ++ _) {
        inf.readInt(1, n);
        inf.readSpace();
        inf.readInt(1, n);
        inf.readEoln();
    }
    inf.readEof();
}
