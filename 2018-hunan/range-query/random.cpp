#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int maxlen = std::atoi(argv[1]);
    int n = std::atoi(argv[2]);
    int q = std::atoi(argv[3]);
    printf("%d %d\n", n, q);
    while (q --) {
        int t = rnd.next(1, 2);
        if (t == 1) {
            int l = rnd.next(1, n);
            int r = rnd.next(1, n);
            if (l > r) {
                std::swap(l, r);
            }
            printf("1 %d %d\n", l, r);
        } else {
            int l = rnd.next(1, n - maxlen + 1);
            int r = rnd.next(l, l + maxlen - 1);
            printf("2 %d %d\n", l, r);
        }
    }
}
