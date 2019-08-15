#include "testlib.h"

#include <functional>

int main()
{
    registerValidation();
    int n = inf.readInt(1, 100000);
    inf.readSpace();
    int m = inf.readInt(2, 100099);
    inf.readSpace();
    int q = inf.readInt(1, 100000);
    inf.readEoln();
    ensure(n + 1 <= m && m < n + 100);
    std::vector<int> parent(n, -1);
    std::function<int(int)> find = [&](int u) {
        return ~parent[u] ? parent[u] = find(parent[u]) : u;
    };
    for (int _ = 0; _ < m; ++ _) {
        int a = find(inf.readInt(1, n) - 1);
        inf.readSpace();
        int b = find(inf.readInt(1, n) - 1);
        inf.readEoln();
        if (a != b) {
            parent[a] = b;
        }
    }
    for (int i = 0; i < n; ++ i) {
        ensure(find(0) == find(i));
    }
    for (int _ = 0; _ < q; ++ _) {
        inf.readInt(1, n);
        inf.readSpace();
        inf.readInt(1, n);
        inf.readEoln();
    }
    inf.readEof();
}
