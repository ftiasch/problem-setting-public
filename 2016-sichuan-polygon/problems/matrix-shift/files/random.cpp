#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int q = std::atoi(argv[2]);
    printf("%d %d\n", n, q);
    for (int _ = 0; _ < q; ++ _ ) {
        int t = rnd.next(1, 2);
        int l = rnd.next(0, n - 1);
        int r = rnd.next(0, n - 1);
        if (l > r) {
            std::swap(l, r);
        }
        printf("%d %d %d %d\n", t, l, r, rnd.next(0, n - 1));
    }
    return 0;
}
