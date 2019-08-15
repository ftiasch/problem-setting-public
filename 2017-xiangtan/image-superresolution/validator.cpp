#include "testlib.h"

int main()
{
    registerValidation();
    int test_count = 0;
    while (!inf.eof()) {
        test_count ++;
        int n = inf.readInt(1, 10);
        inf.readSpace();
        int m = inf.readInt(1, 10);
        inf.readSpace();
        int a = inf.readInt(1, 10);
        inf.readSpace();
        int b = inf.readInt(1, 10);
        inf.readEoln();
        for (int i = 0; i < n; ++ i) {
            inf.readToken(format("[01]{%d}", m));
            inf.readEoln();
        }
    }
    ensure(1 <= test_count && test_count <= 10);
    inf.readEof();
}
