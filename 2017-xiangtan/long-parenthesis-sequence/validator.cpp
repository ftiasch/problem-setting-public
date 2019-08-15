#include "testlib.h"

int main()
{
    registerValidation();
    int sum_n = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, 100000, "n");
        sum_n += n;
        inf.readEoln();
        int length = 0;
        for (int i = 0; i < n; ++ i) {
            auto l = inf.readInt(1, 1000000000);
            inf.readSpace();
            inf.readToken("[()]");
            inf.readSpace();
            inf.readInt(1, 1000000000);
            inf.readEoln();
            length += l;
            ensure(length <= 1000000000);
        }
        ensure(length % 2 == 0);
    }
    ensure(sum_n <= 1000000);
    inf.readEof();
}
