#include "testlib.h"

#include <cstdio>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int m = std::atoi(argv[1]);
    std::vector<int> ns;
    for (int i = 2; i + 1 < argc; i += 2) {
        auto c = std::atoi(argv[i]);
        auto n = std::atoi(argv[i + 1]);
        while (c --) {
            ns.push_back(n);
        }
    }
    for (auto&& n : ns) {
        printf("%d\n", n);
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", rnd.next(1, m), " \n"[i == n - 1]);
        }
    }
}
