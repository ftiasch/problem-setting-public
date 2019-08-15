#include "testlib.h"

int main()
{
    registerValidation();
    while (!inf.eof()) {
        int x[4], y[4];
        for (int i = 0; i < 4; ++ i) {
            x[i] = inf.readInt(0, 10000, format("x[%d]", i));
            inf.readSpace();
            y[i] = inf.readInt(0, 10000, format("y[%d]", i));
            if (i & 1) {
                inf.readEoln();
            } else {
                inf.readSpace();
            }
        }
        ensure(x[0] != x[1] && y[0] != y[1]);
        ensure(x[2] < x[3] && y[2] < y[3]);
    }
    inf.readEof();
}
