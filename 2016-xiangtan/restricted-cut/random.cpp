#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    int c = std::atoi(argv[3]);
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (i != j) {
                edges.emplace_back(i, j);
            }
        }
    }
    shuffle(edges.begin(), edges.end());
    edges.resize(std::min((int)edges.size(), m));
    printf("%d %d\n", n, (int)edges.size());
    for (auto&& e : edges) {
        printf("%d %d %d\n", e.first + 1, e.second + 1, rnd.next(1, c));
    }
}
