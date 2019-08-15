#include "testlib.h"

const int MOD = (int)1e9 + 7;

int main()
{
    registerValidation();
    int sum_n = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, 100000, "n");
        inf.readEoln();
        sum_n += n;
        ensure(sum_n <= 1000000);
        std::vector<int> sum(n);
        for (int i = 0; i < n; ++ i) {
            inf.readInt(0, 100000);
            if (i + 1 < n) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
    }
    inf.readEof();
}
