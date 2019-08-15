#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(1, 50000);
    inf.readSpace();
    int q = inf.readInt(1, 100000);
    inf.readEoln();
    inf.readToken(format("[a-z]{%d}", n));
    inf.readEoln();
    int total = 50000;
    while (q --) {
        int index = inf.readInt(0, n);
        inf.readSpace();
        if (index == 0) {
            total -= inf.readToken(format("[a-z]{1,%d}", total)).length();
            ensure(total >= 0);
        } else {
            inf.readToken("[a-z]");
        }
        inf.readEoln();
    }
    inf.readEof();
}
