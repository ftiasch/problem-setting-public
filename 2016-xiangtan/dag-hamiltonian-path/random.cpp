#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    int w = std::atoi(argv[3]);
    std::vector<std::pair<int, int>> edges;
    if (rnd.next(0, 1)) {
        for (int i = 1; i < n; ++ i) {
            edges.emplace_back(i, i + 1);
        }
    }
    while (static_cast<int>(edges.size()) < m) {
        int a = 0;
        int b = 0;
        while (a == b) {
            a = rnd.next(1, n);
            b = rnd.next(1, n);
        }
        if (a > b) {
            std::swap(a, b);
        }
        edges.emplace_back(a, b);
    }
    shuffle(edges.begin(), edges.end());
    printf("%d %d\n", n, m);
    for (auto&& e : edges) {
        printf("%d %d %d\n", e.first, e.second, rnd.next(1, w));
    }
    return 0;
}
