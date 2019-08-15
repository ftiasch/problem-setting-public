#include "testlib.h"

#include <functional>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> random_tree(int n)
{
    std::vector<int> parent(n, -1);
    std::function<int(int)> find = [&](int u) {
        return ~parent[u] ? parent[u] = find(parent[u]) : u;
    };
    std::vector<std::pair<int, int>> edges;
    for (int _ = 0; _ < n - 1; ++ _) {
        while (true) {
            int a = rnd.next(0, n - 1);
            int b = rnd.next(0, n - 1);
            int u = find(a);
            int v = find(b);
            if (u != v) {
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
    int n = std::atoi(argv[1]);
    int m = n + rnd.next(1, std::atoi(argv[2]));
    int q = std::atoi(argv[3]);

    auto edges = random_tree(n);
    for (int i = n - 1; i < m; ++ i) {
        int a = rnd.next(0, n - 1);
        int b = rnd.next(0, n - 1);
        edges.emplace_back(a, b);
    }

    printf("%d %d %d\n", n, m, q);
    for (auto&& e : edges) {
        printf("%d %d\n", 1 + e.first, 1 + e.second);
    }
    for (int _ = 0; _ < q; ++ _) {
        int a = rnd.next(1, n);
        int b = rnd.next(1, n);
        printf("%d %d\n", a, b);
    }
}
