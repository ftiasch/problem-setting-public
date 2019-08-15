#include "testlib.h"

#include <bits/stdc++.h>

int find(std::vector<int>& parent, int u)
{
    if (parent[u] != u) {
        parent[u] = find(parent, parent[u]);
    }
    return parent[u];
}

int main()
{
    registerValidation();
    int sum_n = 0;
    while (!inf.eof()) {
        int n = inf.readInt(2, 5000);
        inf.readSpace();
        inf.readInt(1, n * n);
        inf.readSpace();
        inf.readInt(0, n - 1);
        inf.readSpace();
        inf.readInt(0, n - 1);
        inf.readSpace();
        inf.readInt(0, n - 1);
        inf.readSpace();
        inf.readInt(0, n - 1);
        inf.readEoln();
        std::vector<int> parent(n);
        for (int i = 0; i < n; ++ i) {
            parent[i] = i;
        }
        for (int i = 0; i < n - 1; ++ i) {
            int a = inf.readInt(0, n - 1);
            inf.readSpace();
            int b = inf.readInt(0, n - 1);
            inf.readEoln();
            ensure(find(parent, a) != find(parent, b));
            parent[find(parent, a)] = find(parent, b);
        }
        sum_n += n;
    }
    fprintf(stderr, "sum n = %d\n", sum_n);
    ensure(sum_n <= 25000);
    inf.readEof();
}
