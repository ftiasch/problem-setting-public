#include "testlib.h"

int main()
{
    registerValidation();
    int tests = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, 100000);
        inf.readSpace();
        int m = inf.readInt(1, 10);
        inf.readSpace();
        int q = inf.readInt(1, 100000);
        inf.readEoln();
        for (int i = 0; i < m; ++ i) {
            int a = inf.readInt(1, n);
            inf.readSpace();
            inf.readInt(a, n);
            inf.readEoln();
        }
        for (int i = 0; i < q; ++ i) {
            inf.readInt(1, 1000000000);
            inf.readEoln();
        }
        tests ++;
    }
    ensure(tests <= 5);
    inf.readEof();
}
