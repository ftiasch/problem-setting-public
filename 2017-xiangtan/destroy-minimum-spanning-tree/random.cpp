#include "testlib.h"

#include <functional>
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
    std::vector<std::tuple<int, int, int>> params;
    for (int i = 1; i + 3 < argc; i += 4) {
        auto c = std::atoi(argv[i]);
        auto n = std::atoi(argv[i + 1]);
        auto m = std::atoi(argv[i + 2]);
        auto w = std::atoi(argv[i + 3]);
        while (c --) {
            params.emplace_back(n, m, w);
        }
    }
    for (auto&& param : params) {
        int n = std::get<0>(param);
        int m = std::get<1>(param);
        int w = std::get<2>(param);
        auto tree = random_tree(n, 1);
        while (static_cast<int>(tree.size()) < m) {
            int a = rnd.next(0, n - 1);
            int b = rnd.next(0, n - 1);
            if (a != b) {
                tree.emplace_back(a, b);
            }
        }
        shuffle(tree.begin(), tree.end());
        printf("%d %d\n", n, m);
        for (auto&& edge : tree) {
            printf("%d %d %d\n", edge.first + 1, edge.second + 1, rnd.next(1, w));
        }
    }
}
