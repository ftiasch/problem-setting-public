#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    int w = std::atoi(argv[3]);
    printf("%d %d\n", n, m);
    for (int _ = 0; _ < m; ++ _) {
        int mask = rnd.next(1, (1 << n) - 1);
        printf("%d %d", rnd.next(1, w), __builtin_popcount(mask));
        for (int i = 0; i < n; ++ i) {
            if (mask >> i & 1) {
                printf(" %d", i + 1);
            }
        }
        puts("");
    }
}
