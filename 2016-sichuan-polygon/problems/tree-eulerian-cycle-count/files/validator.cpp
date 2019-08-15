#include "testlib.h"

#include <functional>

int main()
{
    registerValidation();
    int n = inf.readInt(1, 100000);
    inf.readEoln();
    std::vector<int> parent(n, -1);
    std::function<int(int)> find = [&](int u) {
        return ~parent[u] ? parent[u] = find(parent[u]) : u;
    };
    int m = 1000000;
    for (int _ = 0; _ < n - 1; ++ _) {
        int a = find(inf.readInt(1, n) - 1);
        inf.readSpace();
        int b = find(inf.readInt(1, n) - 1);
        inf.readSpace();
        ensure(a != b);
        parent.at(a) = b;
        int c = inf.readInt(1, m);
        inf.readEoln();
        m -= c;
    }
    inf.readEof();
}
