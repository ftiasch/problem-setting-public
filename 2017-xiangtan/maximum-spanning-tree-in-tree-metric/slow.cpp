#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

using LL = long long;

const LL INF = (LL)1e18;

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<std::vector<LL>> graph(n, std::vector<LL>(n, INF));
        for (int i = 0; i < n - 1; ++ i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a --;
            b --;
            graph.at(a).at(b) = graph.at(b).at(a) = c;
        }
        for (int k = 0; k < n; ++ k) {
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < n; ++ j) {
                    graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        using Edge = std::pair<int, std::pair<int, int>>;
        std::vector<Edge> edges;
        for (int i = 0; i < n; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                edges.emplace_back(graph[i][j], std::make_pair(i, j));
            }
        }
        std::sort(edges.begin(), edges.end(), std::greater<Edge>());
        LL result = 0;
        std::vector<int> parent(n, -1);
        std::function<int(int)> find = [&](int u) {
            return ~parent[u] ? parent[u] = find(parent[u]) : u;
        };
        for (auto&& edge : edges) {
            auto&& a = edge.second.first;
            auto&& b = edge.second.second;
            if (find(a) != find(b)) {
                result += edge.first;
                parent.at(find(a)) = find(b);
            }
        }
        std::cout << result << std::endl;
    }
}
