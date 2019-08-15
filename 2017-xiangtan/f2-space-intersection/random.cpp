#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int n = std::atoi(argv[2]);
    int b = std::atoi(argv[3]);
    for (int _ = 0; _ < T; ++ _) {
        printf("%d\n", n);
        for (int __ = 0; __ < 2; ++ __) {
            int r = rnd.next(0, b);
            std::vector<long long> base;
            for (int i = 0; i < r; ++ i) {
                base.push_back(rnd.next(0LL, (1LL << b) - 1));
            }
            for (int i = 0; i < n; ++ i) {
                long long result = 0;
                for (int j = 0; j < r; ++ j) {
                    if (rnd.next(0, 1)) {
                        result ^= base.at(j);
                    }
                }
                printf("%lld%c", result, " \n"[i == n - 1]);
            }
        }
    }
}
