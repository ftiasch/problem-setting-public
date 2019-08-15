#include "testlib.h"

#include <algorithm>
#include <cstdio>

const int MOD = (int)1e9 + 7;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    std::vector<int> ns;
    for (int i = 1; i + 1 < argc; i += 2) {
        auto c = std::atoi(argv[i]);
        auto n = std::atoi(argv[i + 1]);
        while (c --) {
            ns.push_back(n);
        }
    }
    for (auto&& n : ns) {
        printf("%d\n", n);
        std::vector<int> sum(n);
        for (int i = 0; i < n - 1; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int a = rnd.next(0, MOD - 1);
                (sum.at(j) += MOD - a) %= MOD;
                printf("%d%c", a, " \n"[j == n - 1]);
            }
        }
        for (int j = 0; j < n; ++ j) {
            printf("%d%c", sum.at(j), " \n"[j == n - 1]);
        }
    }
}
