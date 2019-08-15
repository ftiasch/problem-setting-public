#include "testlib.h"

const int MOD = (int)1e9 + 7;

int main()
{
    registerValidation();
    int test_count = 0;
    while (!inf.eof()) {
        test_count ++;
        int n = inf.readInt(1, 1000, "n");
        inf.readEoln();
        // std::vector<int> sum(n);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                inf.readInt(0, 1000000000);
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
    ensure(1 <= test_count && test_count <= 10);
    inf.readEof();
}
