#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(1, 5);
    inf.readEoln();
    for (int _ = 0; _ < n; ++ _) {
        int low = inf.readInt(1, 1000);
        inf.readSpace();
        int high = inf.readInt(1, 1000);
        inf.readEoln();
        ensure(low <= high);
    }
    inf.readEof();
}
