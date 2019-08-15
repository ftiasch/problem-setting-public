#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    int w = std::atoi(argv[3]);
    printf("%d %d\n", n, rnd.next(1, m));
    for (int i = 1; i <= n; ++ i) {
        printf("%d%c", rnd.next(0, w), " \n"[i == n]);
    }
    for (int i = 1; i <= n; ++ i) {
        printf("%d%c", rnd.next(0, w), " \n"[i == n]);
    }
}
