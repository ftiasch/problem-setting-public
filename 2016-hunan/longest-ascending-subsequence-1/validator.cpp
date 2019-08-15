#include "testlib.h"

#include <set>

int main()
{
    registerValidation();
    int n = inf.readInt(1, (int)1e5, "n");
    inf.readEoln();
    std::set<int> s;
    for (int i = 0; i < n; ++ i) {
        int a = inf.readInt(0, n, format("p[%d]", i));
        if (1 <= a && a <= n) {
            ensure(s.insert(a).second);
        }
        if (i + 1 < n) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
    inf.readEof();
}
