#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(1, (int)1e3);
    inf.readSpace();
    int m = inf.readInt(1, (int)1e3);
    inf.readEoln();
    for (int i = 0; i < n; ++ i) {
        inf.readToken(format("[01]{%d}", m));
        inf.readEoln();
    }
    inf.readEof();
}
