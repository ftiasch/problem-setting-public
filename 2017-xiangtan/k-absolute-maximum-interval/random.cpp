#include "testlib.h"

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
        printf("%d %d %d\n", n, rnd.next(1, n + 1 >> 1), rnd.next(1, 10000));
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", rnd.next(-10000, 10000), " \n"[i == n - 1]);
        }
    }
}
