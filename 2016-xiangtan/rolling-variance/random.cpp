#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = rnd.next(2, n);
    int w = std::atoi(argv[2]);
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++ i) {
        printf("%d%c", rnd.next(-w, w), " \n"[i == n - 1]);
    }
}
