#include <bits/stdc++.h>

const int N = 5000;

int parent[N], depth[N], dfn[N];
std::vector<int> tree[N];

void prepare(int p, int u)
{
    depth[u] = ~p ? depth[p] + 1 : 0;
    parent[u] = p;
    for (int v : tree[u]) {
        if (v != p) {
            prepare(u, v);
        }
    }
}

int lca(int u, int v)
{
    while (u != v) {
        if (depth[u] > depth[v]) {
            u = parent[u];
        } else {
            v = parent[v];
        }
    }
    return u;
}

int z = 0;
bool vis[N];

int dfs(int p, int u)
{
    vis[u] = true;
    dfn[u] = ~p ? dfn[p] + 1 : 0;
    int low = dfn[u];
    int result = (p != -1);
    for (int v : tree[u]) {
        if (vis[v]) {
            low = std::min(low, dfn[v]);
        } else {
            int ret = dfs(u, v);
            result += ret >= dfn[u];
            low = std::min(low, ret);
        }
    }
    z ^= result;
    return low;
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
        z = 0;
        for (int i = 0; i < n; ++ i) {
            z ^= tree[i].size();
        }
        while (m --) {
            int u = (a * x + b * y + z) % n;
            int v = (b * x + a * y + z) % n;
            int w = lca(u, v);
            tree[u].push_back(w);
            tree[w].push_back(u);
            z = 0;
            memset(vis, 0, sizeof(*vis) * n);
            dfs(-1, rand() % n);
// fprintf(stderr, "add %d %d = %d\n", u, w, z);
            x = u, y = v;
        }
        printf("%d %d\n", x, y);
    }
}
