#include "testlib.h"

#include <cstdio>
#include <numeric>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    std::vector<std::pair<int, int>> ns;
    for (int i = 1; i + 1 < argc; i += 3) {
        auto c = std::atoi(argv[i]);
        auto n = std::atoi(argv[i + 1]);
        auto m = std::atoi(argv[i + 2]);
        while (c --) {
            ns.emplace_back(n, m);
        }
    }
    for (auto&& iterator : ns) {
        int n = iterator.first;
        int m = iterator.second;
        printf("%d %d\n", n, m);
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", rnd.next(0, 1), " \n"[i == n - 1]);
        }
        std::vector<int> p(m);
        std::iota(p.begin(), p.end(), 1);
        shuffle(p.begin(), p.end());
        for (int i = 0; i < m; ++ i) {
            printf("%d%c", p.at(i), " \n"[i == m - 1]);
        }
    }
}
