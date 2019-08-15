#include "testlib.h"

#include <bits/stdc++.h>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int q = std::atoi(argv[2]);
    int m = std::atoi(argv[3]);
    int w = std::atoi(argv[4]);
    printf("%d %d\n", n, q);
    for (int i = 0; i < n; ++ i) {
        printf("%d%c", rnd.wnext(1, m, w), " \n"[i == n - 1]);
    }
    while (q --) {
        int l = rnd.next(1, n);
        int r = rnd.next(1, n);
        if (l > r) {
            std::swap(l, r);
        }
        printf("%d %d\n", l, r);
    }
}
