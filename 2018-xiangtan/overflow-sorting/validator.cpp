#include "testlib.h"

const int INF = 2000000000;

int main()
{
    registerValidation();
    int sum_n = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, 1000);
        inf.readEoln();
        for (int i = 0; i < n; ++ i) {
            inf.readInt(1, INF);
            inf.readSpace();
            inf.readInt(1, INF);
            inf.readSpace();
            inf.readInt(1, INF);
            inf.readEoln();
        }
        sum_n += n;
    }
    fprintf(stderr, "sum n = %d\n", sum_n);
    ensure(sum_n <= 10000);
    inf.readEof();
}
