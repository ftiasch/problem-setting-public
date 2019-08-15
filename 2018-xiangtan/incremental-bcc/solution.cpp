#include <algorithm>
#include <cassert>
#include <cstdio>
#include <utility>
#include <vector>

const int N = 5000;

int parent[N], depth[N], lca[N][N], ans[N], low[N], jump[N][N];
std::vector<int> tree[N];

void prepare(int p, int u)
{
    parent[u] = p;
    depth[u] = ~p ? depth[p] + 1 : 0;
    for (int v : tree[u]) {
        if (v != p) {
            prepare(u, v);
        }
    }
}

int find(int g, int u)
{
    if (u == -1 || jump[g][u] == u) {
        return u;
    }
    return jump[g][u] = find(g, jump[g][u]);
}

int add(int a, int b)
{
    int z = 0;
    int g = depth[b];
    int u = find(g, a);
    while (~u && depth[u] >= depth[b]) {
        if (depth[b] < low[u]) {
            int p = parent[u];
            if (~p) {
                z ^= ans[p];
                if (low[u] >= depth[p] && depth[b] < depth[p]) {
                    ans[p] --;
                }
                assert(ans[p] >= 1);
                z ^= ans[p];
            }
            low[u] = depth[b];
        }
        jump[g][u] = parent[u];
        u = find(g, u);
    }
    return z;
}

int main()
{
    int n, m, a, b, x, y;
    while (scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &x, &y) == 6) {
        for (int i = 0; i < n; ++ i) {
            tree[i].clear();
        }
        for (int i = 0, a, b; i < n - 1; ++ i) {
            scanf("%d%d", &a, &b);
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        prepare(-1, 0);
        std::vector<std::pair<int, int>> order;
        for (int i = 0; i < n; ++ i) {
            order.emplace_back(depth[i], i);
        }
        std::sort(order.begin(), order.end());
        for (int j = 0; j < n; ++ j) {
            int v = order[j].second;
            for (int i = 0; i < j; ++ i) {
                int u = order[i].second;
                lca[u][v] = lca[v][u] = lca[parent[v]][u];
            }
            lca[v][v] = v;
        }
        for (int i = 0; i < n; ++ i) {
            low[i] = depth[i];
            for (int j = 0; j < n; ++ j) {
                jump[i][j] = j;
            }
        }
        int z = 0;
        for (int u = 0; u < n; ++ u) {
            z ^= (ans[u] = tree[u].size());
        }
        while (m --) {
            int u = (a * x + b * y + z) % n;
            int v = (a * y + b * x + z) % n;
            int w = lca[u][v];
            z ^= add(u, w);
// fprintf(stderr, "add %d %d = %d\n", u, w, z);
            x = u, y = v;
        }
        printf("%d %d\n", x, y);
    }
}
