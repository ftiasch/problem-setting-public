#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int n = std::atoi(argv[2]);
    int m = std::atoi(argv[3]);
    while (T --) {
        std::vector<std::pair<int, int>> edges;
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j < i; ++ j) {
                edges.emplace_back(j, i);
            }
        }
        shuffle(edges.begin(), edges.end());
        edges.resize(rnd.next(0, static_cast<int>(edges.size())));
        printf("%d %d\n", n, static_cast<int>(edges.size()));
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", rnd.next(0, m), " \n"[i == n - 1]);
        }
        for (auto&& e : edges) {
            printf("%d %d\n", e.first, e.second);
        }
    }
}
