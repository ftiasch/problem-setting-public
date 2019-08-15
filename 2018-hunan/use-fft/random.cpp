#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int N = std::atoi(argv[2]);
    int w = std::atoi(argv[3]);
    int v = std::atoi(argv[4]);
    while (T --) {
        int n = rnd.wnext(1, N, w);
        int m = rnd.wnext(1, N, w);
        int l = rnd.next(0, n + m);
        int r = rnd.next(0, n + m);
        if (l > r) {
            std::swap(l, r);
        }
        printf("%d %d %d %d\n", n, m, l, r);
        for (int i = 0; i <= n; ++ i) {
            printf("%d%c", rnd.next(0, v), " \n"[i == n]);
        }
        for (int i = 0; i <= m; ++ i) {
            printf("%d%c", rnd.next(0, v), " \n"[i == m]);
        }
    }
}
