#include "testlib.h"

#include <bits/stdc++.h>

int main()
{
    registerValidation();
    int tests = 0, ltests = 0;
    while (!inf.eof()) {
        int n = inf.readInt(1, 20);
        inf.readSpace();
        int m = inf.readInt(0, n * (n - 1) / 2);
        inf.readEoln();
        for (int i = 0; i < n; ++ i) {
            inf.readInt(0, 1000000000);
            if (i + 1 < n) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
        std::set<std::pair<int, int>> edges;
        for (int i = 0; i < m; ++ i) {
            int a = inf.readInt(1, n);
            inf.readSpace();
            int b = inf.readInt(a + 1, n);
            inf.readEoln();
            ensure(edges.emplace(a, b).second);
        }
        tests ++;
        ltests += n > 10;
    }
    ensure(tests <= 5000 && ltests <= 1);
    inf.readEof();
}
