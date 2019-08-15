#include <cstdio>
#include <vector>
#include <queue>

int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    std::vector<std::vector<int>> edges(n);
    for (int _ = 0; _ < m; ++ _) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --;
        b --;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int _ = 0; _ < q; ++ _) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --;
        b --;
        std::vector<int> d(n, -1);
        d[a] = 0;
        std::queue<int> q;
        q.push(a);
        while (d[b] == -1) {
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                if (!~d[v]) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        printf("%d\n", d[b]);
    }
}
