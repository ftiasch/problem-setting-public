#include "testlib.h"

int find(std::vector<int>& parent, int u)
{
    if (parent.at(u) == -1) {
        return u;
    }
    return parent.at(u) = find(parent, parent.at(u));
}

int main()
{
    registerValidation();
    int sum_n = 0;
    while (!inf.eof()) {
        int n = inf.readInt(2, 50, "n");
        sum_n += n;
        inf.readSpace();
        int m = inf.readInt(n - 1, n * n, "m");
        inf.readEoln();
        std::vector<int> parent(n, -1);
        for (int i = 0; i < m; ++ i) {
            int a = find(parent, inf.readInt(1, n, format("a[%d]", i + 1)) - 1);
            inf.readSpace();
            int b = find(parent, inf.readInt(1, n, format("b[%d]", i + 1)) - 1);
            inf.readSpace();
            inf.readInt(1, 1000000000, format("c[%d]", i + 1));
            inf.readEoln();
            if (a != b) {
                parent.at(a) = b;
            }
        }
        ensure(sum_n <= 1000);
        for (int i = 0; i < n; ++ i) {
            ensure(find(parent, 0) == find(parent, i));
        }
    }
    inf.readEof();
}
