#include <bits/stdc++.h>

int find(std::vector<int>& par, int u)
{
    if (par[u] != u) {
        par[u] = find(par, par[u]);
    }
    return par[u];
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<std::pair<int, std::pair<int, int>>> edges;
        for (int i = 0, a, b, c; i < m; ++ i) {
            scanf("%d%d%d", &a, &b, &c);
            a --, b --;
            edges.emplace_back(c, std::make_pair(a, b));
        }
        std::sort(edges.begin(), edges.end());
        std::vector<int> result(n, INT_MAX / 2);
        for (int msk = 0; msk < 1 << m; ++ msk) {
            std::vector<int> par(n);
            std::iota(par.begin(), par.end(), 0);
            int total = 0;
            for (int i = 0; i < m; ++ i) {
                int c = edges[i].first;
                int a = edges[i].second.first;
                int b = edges[i].second.second;
                if ((msk >> i & 1) && find(par, a) != find(par, b)) {
                    total += c;
                    par[find(par, a)] = find(par, b);
                }
            }
            for (int i = 1; i < n && find(par, 0) == find(par, i); ++ i) {
                result[i] = std::min(result[i], total);
            }
        }
        for (int i = 1; i < n; ++ i) {
            printf("%d\n", result[i]);
        }
    }
}
