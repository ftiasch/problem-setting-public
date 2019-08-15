#include "testlib.h"

int main()
{
    registerValidation();
    int test_count = 0;
    while (!inf.eof()) {
        test_count ++;
        int n = inf.readInt(2, 300, "n");
        inf.readSpace();
        int m = inf.readInt(1, n * (n - 1) / 2, "m");
        inf.readSpace();
        int q = inf.readInt(1, 300, "q");
        inf.readEoln();
        for (int i = 0; i < m; ++ i) {
            int a = inf.readInt(1, n);
            inf.readSpace();
            int b = inf.readInt(1, n);
            inf.readEoln();
            ensure(a < b);
        }
        for (int i = 0; i < q; ++ i) {
            inf.readInt(1, n);
            inf.readEoln();
        }
    }
    ensure(1 <= test_count && test_count <= 10);
    inf.readEof();
}
