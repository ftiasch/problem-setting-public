#include <bits/stdc++.h>

template<typename T>
using PQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

void update(int& x, int a)
{
    x = std::min(x, a);
}

int find(std::vector<int>& parent, int u)
{
    if (parent[u] != u) {
        parent[u] = find(parent, parent[u]);
    }
    return parent[u];
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<std::vector<std::pair<int, int>>> graph(n);
        std::vector<std::pair<int, std::pair<int, int>>> edges;
        for (int i = 0, a, b, c; i < m; ++ i) {
            scanf("%d%d%d", &a, &b, &c);
            a --, b --;
            graph[a].emplace_back(b, c);
            graph[b].emplace_back(a, c);
            edges.emplace_back(c, std::make_pair(a, b));
        }
        std::sort(edges.begin(), edges.end());
        int n2 = std::max(n >> 1, 1);
        std::vector<std::vector<int>> dp(1 << n2, std::vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n2; ++ i) {
            dp[1 << i][i] = 0;
        }
        for (int msk = 0; msk < 1 << n2; ++ msk) {
            for (int sub = msk - 1 & msk; sub > 0; sub = sub - 1 & msk) {
                for (int u = 0; u < n; ++ u) {
                    update(dp[msk][u], dp[sub][u] + dp[msk ^ sub][u]);
                }
            }
            auto& dist = dp[msk];
            PQ<std::pair<int, int>> pq;
            for (int i = 0; i < n; ++ i) {
                pq.emplace(dist[i], i);
            }
            while (!pq.empty()) {
                auto top = pq.top();
                pq.pop();
                int u = top.second;
                if (top.first == dist[u]) {
                    for (auto&& e : graph[u]) {
                        int v = e.first;
                        if (dist[u] + e.second < dist[v]) {
                            dist[v] = dist[u] + e.second;
                            pq.emplace(dist[v], v);
                        }
                    }
                }
            }
        }
        std::vector<int> result(n, INT_MAX / 2);
        for (int i = 0; i < n2; ++ i) {
            result[i] = dp[(1 << i + 1) - 1][i];
        }
        for (int msk = 0; msk < 1 << n - n2; ++ msk) {
            std::vector<int> parent(n);
            std::iota(parent.begin(), parent.end(), 0);
            auto check = [n2, msk](int u)
            {
                return u < n2 || (msk >> u - n2 & 1);
            };
            int total = 0;
            for (auto&& e : edges) {
                int c = e.first;
                int a = e.second.first;
                int b = e.second.second;
                if (check(a) && check(b) && find(parent, a) != find(parent, b)) {
                    total += c;
                    parent[find(parent, a)] = find(parent, b);
                }
            }
            for (int i = 1; i < n && find(parent, 0) == find(parent, i); ++ i) {
                if (i >= n2) {
                    update(result[i], total);
                }
            }
        }
        for (int i = 1; i < n; ++ i) {
            printf("%d\n", result[i]);
        }
    }
}
