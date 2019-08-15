#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int N = std::atoi(argv[2]);
    int w = std::atoi(argv[3]);
    int q = std::atoi(argv[4]);
    while (T --) {
        int n = rnd.wnext(1, N, w);
        int m = rnd.wnext(1, N, w);
        printf("%d %d %d\n", n, m, q);
        for (int i = 0; i < q; ++ i) {
            int t = rnd.next(1, 2);
            int max = t == 1 ? n : m;
            int l = rnd.next(1, max);
            int r = rnd.next(1, max);
            if (l > r) {
                std::swap(l, r);
            }
            printf("%d %d %d\n", t, l, r);
        }
    }
}
