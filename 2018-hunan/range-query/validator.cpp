#include "testlib.h"

const int N = 1e5;
const int MAX_LEN = 3;

int main()
{
    registerValidation();
    int tests = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, N);
        inf.readSpace();
        int q = inf.readInt(1, N);
        inf.readEoln();
        for (int _ = 0; _ < q; ++ _) {
            int t = inf.readInt(1, 2);
            inf.readSpace();
            int l = inf.readInt(1, n);
            inf.readSpace();
            int r = inf.readInt(l, n);
            inf.readEoln();
            if (t == 2) {
                ensure(r - l + 1 <= MAX_LEN);
            }
        }
        tests ++;
    }
    ensure(tests <= 10);
    inf.readEof();
}
