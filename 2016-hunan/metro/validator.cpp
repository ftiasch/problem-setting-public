#include "testlib.h"

#include <numeric>
#include <vector>

int find(std::vector<int>& parent, int u)
{
    if (parent.at(u) != u) {
        parent.at(u) = find(parent, parent.at(u));
    }
    return parent.at(u);
}

int main()
{
    registerValidation();
    int n = inf.readInt(2, 1e5);
    inf.readSpace();
    int m = inf.readInt(1, 1e5);
    inf.readEoln();
    std::vector<int> parent(n);
    std::iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < m; ++ i) {
        int a = inf.readInt(1, n) - 1;
        inf.readSpace();
        int b = inf.readInt(1, n) - 1;
        inf.readSpace();
        inf.readInt(1, n);
        inf.readSpace();
        inf.readInt(1, (int)1e9);
        inf.readEoln();
        parent.at(find(parent, a)) = find(parent, b);
    }
    inf.readEof();
    for (int i = 0; i < n; ++ i) {
        ensure(find(parent, 0) == find(parent, i));
    }
}
