#include "testlib.h"

int main()
{
    registerValidation();
    int test_count = 0;
    while (!inf.eof()) {
        test_count ++;
        int n = inf.readInt(1, 50, "n");
        inf.readEoln();
        for (int _ = 0; _ < 2; ++ _) {
            for (int i = 0; i < n; ++ i) {
                inf.readLong(0LL, (1LL << 60) - 1);
                if (i + 1 < n) {
                    inf.readSpace();
                } else {
                    inf.readEoln();
                }
            }
        }
    }
    ensure(1 <= test_count && test_count <= 5000);
    inf.readEof();
}
