#include <bits/stdc++.h>

int main()
{
    int n, m, q;
    while (scanf("%d%d%d", &n, &m, &q) == 3) {
        std::vector<int> parent(n * m);
        std::iota(parent.begin(), parent.end(), 0);
        std::function<int(int)> find = [&](int u)
        {
            if (parent[u] != u) {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        };

        auto add = [&](int x1, int y1, int x2, int y2) -> bool
        {
            int u = x1 * m + y1;
            int v = x2 * m + y2;
            if (find(u) == find(v)) {
                return false;
            }
            parent[find(u)] = find(v);
            return true;
        };

        int count = n * m;
        while (q --) {
            int t, l, r;
            scanf("%d%d%d", &t, &l, &r);
            l --;
            if (t == 1) {
                for (int i = l; i < r; ++ i) {
                    for (int j = 1; j < m; ++ j) {
                        count -= add(i, j, i, j - 1);
                    }
                }
            } else {
                for (int i = 1; i < n; ++ i) {
                    for (int j = l; j < r; ++ j) {
                        count -= add(i, j, i - 1, j);
                    }
                }
            }
            printf("%d\n", count);
        }
    }
}
