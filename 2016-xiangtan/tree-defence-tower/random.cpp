#include "testlib.h"

#include <functional>
#include <numeric>

std::vector<std::pair<int, int>> random_tree(int n, int w)
{
    std::vector<int> parent(n, -1);
    std::function<int(int)> find = [&](int u) {
        return ~parent[u] ? parent[u] = find(parent[u]) : u;
    };
    std::vector<std::pair<int, int>> edges;
    for (int _ = 0; _ < n - 1; ++ _) {
        while (true) {
            int a = rnd.wnext(0, n - 1, w);
            int b = rnd.next(0, n - 1);
            int u = find(a);
            int v = find(b);
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
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    int w1 = std::atoi(argv[3]);
    int w2 = std::atoi(argv[4]);
    printf("%d\n", n);
    for (int i = 0; i < n; ++ i) {
        printf("%d%c", rnd.wnext(1, m, w1), " \n"[i == n - 1]);
    }
    for (auto&& e : random_tree(n, w2)) {
        printf("%d %d\n", 1 + e.first, 1 + e.second);
    }
}
