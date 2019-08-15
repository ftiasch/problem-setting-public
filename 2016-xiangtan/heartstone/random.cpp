#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    int u = std::atoi(argv[3]);
    int w = std::atoi(argv[4]);
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++ i) {
        printf("%d%c", rnd.wnext(1, u, w), " \n"[i == n - 1]);
    }
}
