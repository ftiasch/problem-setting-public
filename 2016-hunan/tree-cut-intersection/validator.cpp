#include "testlib.h"

#include <functional>

int main()
{
    registerValidation();
    int n = inf.readInt(2, 100000);
    inf.readEoln();
    for (int i = 0; i < n; ++ i) {
        inf.readInt(1, n);
        if (i + 1 < n) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
    std::vector<int> parent(n, -1);
    std::function<int(int)> find = [&](int u) {
        return ~parent[u] ? parent[u] = find(parent[u]) : u;
    };
    for (int i = 0; i < n - 1; ++ i) {
        int a = find(inf.readInt(1, n) - 1);
        inf.readSpace();
        int b = find(inf.readInt(1, n) - 1);
        inf.readEoln();
        ensure(a != b);
        parent.at(a) = b;
    }
    inf.readEof();
}
