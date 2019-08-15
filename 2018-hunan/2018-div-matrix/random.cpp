#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int sn = std::atoi(argv[2]);
    int ln = std::atoi(argv[3]);
    for (int i = 1; i <= sn; ++ i) {
        for (int j = 1; j <= sn; ++ j) {
            T --;
            printf("%d %d\n", i, j);
        }
    }
    T --;
    printf("%d %d\n", ln, ln);
    while (T-- > 0) {
        int n = rnd.next(1, ln);
        int m = rnd.next(1, ln);
        printf("%d %d\n", n, m);
    }
}
