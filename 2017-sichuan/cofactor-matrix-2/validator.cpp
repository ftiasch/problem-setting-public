#include "testlib.h"

const int MOD = (int)1e9 + 7;

int main()
{
    registerValidation();
    int sum_n = 0;
    while (!inf.eof()) {
        int n = inf.readInt(2, 500, "n");
        inf.readEoln();
        sum_n += n;
        ensure(sum_n <= 5000);
        std::vector<int> sum(n);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int a = inf.readInt(0, MOD - 1);
                if (j + 1 < n) {
                    inf.readSpace();
                } else {
                    inf.readEoln();
                }
                (sum.at(j) += a) %= MOD;
            }
        }
        for (int i = 0; i < n; ++ i) {
            ensure(sum.at(i) == 0);
        }
    }
    inf.readEof();
}
