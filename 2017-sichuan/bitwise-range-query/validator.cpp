#include "testlib.h"

int main()
{
    registerValidation();
    int test_count = 0;
    while (!inf.eof()) {
        test_count ++;
        int n = inf.readInt(1, 100000000, "n");
        inf.readSpace();
        inf.readInt(2, 100000, "m");
        inf.readSpace();
        inf.readInt(0, 15, "a");
        inf.readSpace();
        inf.readInt(0, 15, "b");
        inf.readSpace();
        int q = inf.readInt(1, 13, "q");
        inf.readEoln();
        while (q --) {
            int l = inf.readInt(1, n);
            inf.readSpace();
            int r = inf.readInt(1, n);
            inf.readSpace();
            inf.readInt(0, 15);
            inf.readEoln();
            ensure(l <= r);
        }
    }
    ensure(1 <= test_count && test_count <= 10);
    inf.readEof();
}
