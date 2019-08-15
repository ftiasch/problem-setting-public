#include "testlib.h"

const int MOD = (int)1e9 + 7;

int main()
{
    registerValidation();
    int sum_n = 0;
    while (!inf.eof()) {
        int n = inf.readInt(2, 200, "n");
        inf.readEoln();
        sum_n += n;
        ensure(sum_n <= 2000);
        // std::vector<int> sum(n);
        for (int i = 0; i < n - 1; ++ i) {
            for (int j = 0; j < n; ++ j) {
                inf.readInt(0, MOD - 1);
                if (j + 1 < n) {
                    inf.readSpace();
                } else {
                    inf.readEoln();
                }
                // (sum.at(j) += a) %= MOD;
            }
        }
        // for (int i = 0; i < n; ++ i) {
        //     ensure(sum.at(i) == 0);
        // }
    }
    inf.readEof();
}
