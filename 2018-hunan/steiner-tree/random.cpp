#include <bits/stdc++.h>

#include "testlib.h"

std::set<std::pair<int, int>> random_graph(int n, int m)
{
    std::vector<int> parent(n, -1);
    std::function<int(int)> find = [&](int u) {
        return ~parent[u] ? parent[u] = find(parent[u]) : u;
    };
    std::set<std::pair<int, int>> edges;
    for (auto _ = 0; _ < n - 1; ++ _) {
        while (true) {
            auto a = rnd.next(0, n - 1);
            auto b = rnd.next(0, n - 1);
            if (a > b) {
                std::swap(a, b);
            }
            auto u = find(a);
            auto v = find(b);
            if (u != v) {
                edges.emplace(a, b);
                parent[u] = v;
                break;
            }
        }
    }
    for (int i = n - 1; i < m; ++ i) {
        while (true) {
            auto a = rnd.next(0, n - 1);
            auto b = rnd.next(0, n - 1);
            if (a > b) {
                std::swap(a, b);
            }
            if (a != b && edges.emplace(a, b).second) {
                break;
            }
        }
    }
    return edges;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = rnd.next(n - 1, n * (n - 1) / 2);
    int w = std::atoi(argv[2]);
    std::vector<std::pair<int, int>> edges;
    for (auto&& e : random_graph(n, m)) {
        edges.push_back(e);
    }
    shuffle(edges.begin(), edges.end());
    printf("%d %d\n", n, m);
    for (auto&& e : edges) {
        int a = e.first;
        int b = e.second;
        if (rnd.next(0, 1)) {
            std::swap(a, b);
        }
        printf("%d %d %d\n", a + 1, b + 1, rnd.next(1, w));
    }
}
