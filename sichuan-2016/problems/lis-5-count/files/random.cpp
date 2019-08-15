#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    int w = std::atoi(argv[3]);
    printf("%d\n", n);
    for (int _ = 0; _ < n; ++ _) {
        int l = rnd.wnext(1, m, w);
        int s = rnd.next(1, m - l + 1);
        printf("%d %d\n", s, s + l - 1);
    }
}
