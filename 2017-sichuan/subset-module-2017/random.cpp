#include "testlib.h"

#include <algorithm>
#include <cstdio>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    std::vector<int> a;
    for (int i = 1; i < 2017; ++ i) {
        a.push_back(i);
    }
    for (int i = 1; i + 1 < argc; i += 2) {
        auto c = std::atoi(argv[i]);
        auto n = std::atoi(argv[i + 1]);
        while (c --) {
            shuffle(a.begin(), a.end());
            int r = 1;
            for (int i = 0; i < n; ++ i) {
                if (rnd.next(0, 1)) {
                    r = r * a.at(i) % 2017;
                }
            }
            if (rnd.next(0, 1)) {
                r = rnd.next(1, 2016);
            }
            printf("%d %d\n", n, r);
            for (int i = 0; i < n; ++ i) {
                printf("%d%c", a.at(i), " \n"[i == n - 1]);
            }
        }
    }
}
