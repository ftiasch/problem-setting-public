#include "testlib.h"

int main()
{
    registerValidation();
    int test_count = 0;
    while (!inf.eof()) {
        test_count ++;
        int n = inf.readInt(1, 20, "n");
        inf.readSpace();
        int m = inf.readInt(1, 500, "m");
        inf.readEoln();
        for (int i = 0; i < n; ++ i) {
            inf.readInt(0, 1);
            if (i + 1 < n) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
        std::set<int> s;
        for (int i = 0; i < m; ++ i) {
            ensure(s.insert(inf.readInt(1, m)).second);
            if (i + 1 < m) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
    }
    ensure(1 <= test_count && test_count <= 10);
    inf.readEof();
}
