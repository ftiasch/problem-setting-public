#include "testlib.h"

#include <cstdio>
#include <functional>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> random_tree(int n, int w)
{
    std::vector<int> parent(n, -1);
    std::function<int(int)> find = [&](int u) {
        return ~parent[u] ? parent[u] = find(parent[u]) : u;
    };
    std::vector<std::pair<int, int>> edges;
    for (auto _ = 0; _ < n - 1; ++ _) {
        while (true) {
            auto a = rnd.next(0, n - 1);
            auto b = (a + rnd.wnext(1, n - 1, w)) % n;
            auto u = find(a);
            auto v = find(b);
            if (u != v) {
                if (rnd.next(0, 1)) {
                    std::swap(a, b);
                }
                edges.emplace_back(a, b);
                parent[u] = v;
                break;
            }
        }
    }
    return edges;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int n = std::atoi(argv[2]);
    int M = std::atoi(argv[3]);
    for (int _ = 0; _ < T; ++ _) {
        auto edges = random_tree(n, 0);
        printf("%d\n", n);
        for (auto&& e : edges) {
            printf("%d %d %d\n", e.first + 1, e.second + 1, rnd.next(1, M));
        }
    }
}
