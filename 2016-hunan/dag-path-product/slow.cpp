#include <cstdio>
#include <cstring>
#include <vector>

const int MOD = (int)1e9 + 7;

typedef std::vector<std::vector<int>> Graph;

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int dfs(const Graph& graph, std::vector<int>& ways, int u)
{
    if (~ways.at(u)) {
        return ways.at(u);
    }
    int result = 0;
    for (auto&& v : graph.at(u)) {
        update(result, dfs(graph, ways, v));
    }
    return ways.at(u) = result;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d", &a.at(i), &b.at(i));
        }
        Graph graph(n);
        for (int i = 0; i < m; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b);
            a --;
            b --;
            graph.at(a).push_back(b);
        }
        int result = 0;
        for (int t = 0; t < n; ++ t) {
            std::vector<int> ways(n, -1);
            ways.at(t) = 1;
            for (int s = 0; s < n; ++ s) {
                if (s != t) {
                    update(result, (long long)a.at(s) * b.at(t) % MOD * dfs(graph, ways, s) % MOD);
                }
            }
        }
        printf("%d\n", result);
    }
}
