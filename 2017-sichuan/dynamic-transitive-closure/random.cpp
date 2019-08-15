#include "testlib.h"

#include <functional>
#include <vector>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    std::vector<std::tuple<int, int>> params;
    for (int i = 1; i + 2 < argc; i += 3) {
        auto c = std::atoi(argv[i]);
        auto n = std::atoi(argv[i + 1]);
        auto q = std::atoi(argv[i + 2]);
        while (c --) {
            params.emplace_back(n, q);
        }
    }
    for (auto&& param : params) {
        int n = std::get<0>(param);
        int q = std::get<1>(param);
        int m = rnd.next(1, n * (n - 1) / 2);
        std::vector<std::pair<int, int>> edges;
        for (int i = 0; i < n; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                edges.emplace_back(i, j);
            }
        }
        shuffle(edges.begin(), edges.end());
        printf("%d %d %d\n", n, m, q);
        for (int i = 0; i < m; ++ i) {
            printf("%d %d\n", edges.at(i).first + 1, edges.at(i).second + 1);
        }
        int v = rnd.next(1, n);
        std::vector<int> vs(n);
        for (int i = 0; i < n; ++ i) {
            vs.push_back(i);
        }
        shuffle(vs.begin(), vs.end());
        while (q --) {
            printf("%d\n", vs.at(rnd.next(0, v - 1)) + 1);
        }
    }
}
