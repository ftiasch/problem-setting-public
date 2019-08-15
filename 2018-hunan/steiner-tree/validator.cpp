#include <bits/stdc++.h>

#include "testlib.h"

int find(std::vector<int>& par, int u)
{
    if (par[u] != u) {
        par[u] = find(par, par[u]);
    }
    return par[u];
}

int main()
{
    registerValidation();
    int stests = 0;
    int ltests = 0;
    while (!inf.eof()) {
        int n = inf.readInt(2, 26);
        inf.readSpace();
        int m = inf.readInt(n - 1, n * (n - 1) / 2);
        inf.readEoln();
        std::vector<int> par(n);
        std::iota(par.begin(), par.end(), 0);
        std::set<std::pair<int, int>> edges;
        for (int i = 0; i < m; ++ i) {
            int a = inf.readInt(1, n) - 1;
            inf.readSpace();
            int b = inf.readInt(1, n) - 1;
            inf.readSpace();
            inf.readInt(1, 1000);
            inf.readEoln();
            if (a > b) {
                std::swap(a, b);
            }
            if (find(par, a) != find(par, b)) {
                par[find(par, a)] = find(par, b);
            }
            ensure(a != b && edges.emplace(a, b).second);
        }
        for (int i = 0; i < n; ++ i) {
            ensure(find(par, 0) == find(par, i));
        }
        (n <= 8 ? stests : ltests) ++;
    }
    ensure(stests <= 95 && ltests <= 5);
    inf.readEof();
}
