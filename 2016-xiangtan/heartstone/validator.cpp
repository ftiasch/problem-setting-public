#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(1, 100000);
    inf.readSpace();
    inf.readInt(0, 100000);
    inf.readEoln();
    for (int i = 0; i < n; ++ i) {
        inf.readInt(1, 10000);
        if (i + 1 < n) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
    inf.readEof();
}
