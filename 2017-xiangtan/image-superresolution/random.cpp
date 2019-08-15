#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int M = std::atoi(argv[2]);
    for (int _ = 0; _ < T; ++ _) {
        int n = rnd.next(1, M);
        int m = rnd.next(1, M);
        int a = rnd.next(1, M);
        int b = rnd.next(1, M);
        printf("%d %d %d %d\n", n, m, a, b);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                printf("%d", rnd.next(0, 1));
            }
            puts("");
        }
    }
}
