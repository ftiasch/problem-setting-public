#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(1, 3000);
    inf.readSpace();
    int m = inf.readInt(1, 3000);
    inf.readSpace();
    int l = inf.readInt(1, 3000);
    inf.readEoln();
    for (int i = 0; i < n; ++ i) {
        inf.readInt(1, l);
        if (i + 1 < n) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
    int total = 0;
    for (int _ = 0; _ < m; ++ _) {
        int k = inf.readInt(1, 3000 - total);
        total += k;
        for (int j = 0; j < k; ++ j) {
            inf.readSpace();
            inf.readInt(1, l);
        }
        inf.readEoln();
    }
    inf.readEof();
}
