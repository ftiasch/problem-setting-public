#include "testlib.h"

#include <bits/stdc++.h>

// #define DEBUG

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int n = std::atoi(argv[2]);
    int m = std::atoi(argv[3]);
    int q = std::atoi(argv[4]);
    int qm = std::atoi(argv[5]);
    while (T --) {
#ifdef DEBUG
        std::vector<int> perm(n);
        std::iota(perm.begin(), perm.end(), 0);
#endif
        printf("%d %d %d\n", n, m, q);
        for (int i = 0; i < m; ++ i) {
            int a = rnd.next(1, n);
            int b = rnd.next(1, n);
            if (a > b) {
                std::swap(a, b);
            }
            printf("%d %d\n", a, b);
#ifdef DEBUG
            std::reverse(perm.data() + a - 1, perm.data() + b);
#endif
        }
#ifdef DEBUG
        int count = 0;
        int longest = 0;
        int shortest = n;
        for (int i = 0; i < n; ++ i) {
            if (~perm[i]) {
                int len = 0;
                int j = i;
                do {
                    int jj = perm[j];
                    perm[j] = -1;
                    j = jj;
                    len ++;
                } while (j != i);
                count ++;
                longest = std::max(longest, len);
                shortest = std::min(shortest, len);
            }
        }
        fprintf(stderr, "cnt=%d max=%d min=%d\n", count, longest, shortest);
#endif
        for (int i = 0; i < q; ++ i) {
            printf("%d\n", rnd.next(1, qm));
        }
    }
}
