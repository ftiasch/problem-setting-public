#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(2, 100000);
    inf.readSpace();
    inf.readInt(2, n);
    inf.readEoln();
    for (int i = 0; i < n; ++ i) {
        inf.readInt(-100, 100);
        if (i + 1 < n) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
    inf.readEof();
}
