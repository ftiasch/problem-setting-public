#include "testlib.h"

void read_ints(int n)
{
    int sum = 1000000;
    for (int i = 0; i < n; ++ i) {
        int x = inf.readInt(0, sum);
        sum -= x;
        if (i + 1 < n) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
}

int main()
{
    registerValidation();
    int n = inf.readInt(1, 100000);
    inf.readSpace();
    int m = inf.readInt(1, 100000);
    inf.readEoln();
    read_ints(n);
    read_ints(m);
    inf.readEof();
}
