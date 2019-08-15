#include "testlib.h"

int main()
{
    registerValidation();
    int test_count = 0;
    while (!inf.eof()) {
        test_count ++;
        int n = inf.readInt(2, 5000, "n");
        inf.readEoln();
        for (int i = 0; i < n; ++ i) {
            inf.readInt(1, n);
            if (i + 1 < n) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
    }
    ensure(1 <= test_count && test_count <= 10);
    inf.readEof();
}
