#include "testlib.h"

#include <algorithm>
#include <cstdio>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int n = std::atoi(argv[2]);
    int M = std::atoi(argv[3]);
    int q = std::atoi(argv[4]);
    for (int _ = 0; _ < T; ++ _) {
        int m = rnd.next(2, M);
        int a = rnd.next(0, 15);
        int b = rnd.next(0, 15);
        printf("%d %d %d %d %d\n", n, m, a, b, q);
        for (int _ = 0; _ < q; ++ _) {
            int l = rnd.next(1, n);
            int r = rnd.next(1, n);
            if (l > r) {
                std::swap(l, r);
            }
            int w = rnd.next(0, 15);
            printf("%d %d %d\n", l, r, w);
        }
    }
}
