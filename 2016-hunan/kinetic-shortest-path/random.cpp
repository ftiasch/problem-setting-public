#include "testlib.h"

#include <numeric>

#define ALL(v) (v).begin(), (v).end()

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    int w = std::atoi(argv[3]);
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (i != j && rnd.wnext(0, 1, w)) {
                edges.emplace_back(i, j);
            }
        }
    }
    std::vector<int> path(n);
    std::iota(path.begin(), path.end(), 0);
    shuffle(path.begin() + 1, path.end());
    for (int i = 0; path[i] != n - 1; ++ i) {
        edges.emplace_back(path[i], path[i + 1]);
    }
    std::sort(ALL(edges));
    edges.erase(std::unique(ALL(edges)), edges.end());
    shuffle(ALL(edges));
    printf("%d %d %d\n", n, (int)edges.size(), rnd.next(1, n * m));
    for (auto&& e : edges) {
        int k = rnd.next(0, m);
        int b = rnd.next(0, m);
        printf("%d %d %d %d\n", e.first + 1, e.second + 1, k, b);
    }
}
