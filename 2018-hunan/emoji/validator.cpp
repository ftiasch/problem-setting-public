#include "testlib.h"

int main()
{
    registerValidation();
    int sum_nm = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, 1000);
        inf.readSpace();
        int m = inf.readInt(1, 1000);
        inf.readEoln();
        for (int i = 0; i < n; ++ i) {
            inf.readToken(format("[v^<>]{%d}", m));
            inf.readEoln();
        }
        sum_nm += n * m;
    }
    ensure(sum_nm <= 2000000);
    inf.readEof();
}
